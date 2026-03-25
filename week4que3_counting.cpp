#include<iostream>
#include<vector>
using namespace std;

// O(n) is worst case time complexity.(counting sort)

void sortarray(vector<int>& arr){
    int max = 0;
    for(int i=0; i<arr.size() ; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    vector<int> newarr(max+1);
    for(int i=0; i<arr.size() ; i++){
        newarr[arr[i]] ++;
    }
    int x = 0;
    for(int i=0; i<newarr.size() ; i++){
        while(newarr[i] != 0){
            arr[x] = i; 
            x++;
            newarr[i]--;
        }
    }
}

int main(){
    int T, n, K;
    cin >>T;
    while(T--){
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n ; i++){
            cin >> arr[i];
        }
        sortarray(arr);
        cin >> K;
        if(K <= n)
            cout << "Kth smallest element = " << arr[K-1] << endl;
        else 
            cout << "Not Present.\n" ;
    }
}