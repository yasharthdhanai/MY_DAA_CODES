#include<iostream>
#include<vector>
using namespace std;

// O(n) is worst case time complexity.

void MaxFrequency(vector<char>& arr){
    vector<int> newarr(26);
    for(int i=0; i<arr.size() ; i++){
        // int x = arr[i] - 97;
        // newarr[x]++;
        newarr[arr[i] -'a'] ++;
    }
    int max = 0;
    char ch;
    for(int i=0; i<newarr.size() ; i++){
        if(newarr[i] > max){
            ch = i+97;
            max = newarr[i];
        }
    }
    if(max == 0 || max == 1)
    cout << "No Duplicates Present.\n";
    else
    cout << ch << " = " <<max << endl ;
}

int main(){
    int T, n;
    cin >>T;
    while(T--){
        cin >> n;
        vector<char> arr(n);
        for(int i=0; i<n ; i++){
            cin >> arr[i];
        }
        MaxFrequency(arr);
    }
}