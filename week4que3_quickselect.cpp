#include<iostream>
#include<vector>

using namespace std;

// Kth smallest element. (quickselect)

int quickselect(vector<int>& arr, int st, int end, int k){
    if(st == end)
        return arr[st];
    int i = st, j = st, piv = end; // we choose last element as pivot
    while(j < end){
        if(arr[j] <= arr[piv]){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
        j++;
    }
    int temp = arr[i];
    arr[i] = arr[piv];
    arr[piv] = temp;
    if(i+1 == k)
        return arr[i];
    else if(i+1 > k)
        return quickselect(arr, st, i-1, k);
    else
        return quickselect(arr, i+1, end, k);
}

int main(){
    int T, n, k;
    cin >> T;
    while(T--){
        cin >> n;
        vector<int>arr(n);
        for(int i=0 ; i<n ;i++){
            cin >> arr[i];
        }
        cin >> k;
        int num;
        num = quickselect(arr, 0, n-1, k);
        cout << num << endl; 
    }
    return 0;
}