#include<iostream>
#include<vector>
using namespace std;

// we take last element as pivot.

int comp = 0, swaps =0;

int partition(vector<int>& arr, int st, int end){
    int i = st-1, j = st, piv = end;
    while(j<=end){
        if(arr[j] <= arr[piv]){
            i++;
            if(i != j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swaps ++;
            }
            j++;
        }
        else{
            j++; 
        }
        comp++;
    }
    // int temp = arr[end];
    // arr[end] = arr[i];
    // arr[i] = temp;
    return i;
}

void qsort(vector<int>& arr, int st, int end){
    if(st >= end)
        return;
    int pivIdx = partition(arr, st, end);
    qsort(arr, st , pivIdx-1);
    qsort(arr, pivIdx+1 , end);
}

int main(){
    int T;
    cin>>T; 
    while(T--){
        int n, target;
        cin>>n;
        vector<int>arr(n);
        for(int i=0 ; i<n ; i++){
            cin >> arr[i];
        }
        qsort(arr, 0 , n-1);
        for(int i=0 ; i<n ; i++){
            cout<< arr[i] << " ";
        }
        cout << endl << "comparisions : " << comp ;
        cout << endl << "swaps : " << swaps << endl;
        comp = 0;
        swaps = 0;
    }
    return 0;
}