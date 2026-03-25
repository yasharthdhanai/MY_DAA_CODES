#include<iostream>
using namespace std;

void selectionsort(int*arr, int n, int* c, int* s){ //move smallest element to 1st pos.
    for(int i=0; i<n-1 ; i++){
        int smallest = i;
        for(int j =i+1; j<n ;j++){
            (*c)++;
            if(arr[j]<arr[smallest]){
                smallest = j;
            }
        }
        if(i != smallest){
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
            (*s)++;
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n, comparision=0, swaps=0 ;
        cin>>n;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin >> arr[i];
        }
        selectionsort(arr, n, &comparision, &swaps);
        for(int i=0 ; i<n ; i++){
            cout << arr[i] << " ";
        }
        cout << endl << "comparisons : "<< comparision;
        cout << endl << "swaps : "<< swaps << endl;
    }
    return 0;
}