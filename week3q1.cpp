#include<iostream>
using namespace std;

void insertionsort(int* arr, int n, int* c, int* s){
    int i=0, j=1;
    while(j < n){
        while(i >= 0){
            (*c)++;
            if(arr[i] <= arr[i+1])
                break;
            else if(arr[i] > arr[i+1]){
                (*s)++;
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
            i--;
        }
        i = j;
        j++;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n, comparision=0, shifts=0;
        cin>>n;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin >> arr[i];
        }
        insertionsort(arr, n, &comparision, &shifts);
        for(int i=0 ; i<n ; i++){
            cout << arr[i] << " ";
        }
        cout << endl << "comparision = " << comparision <<endl;
        cout << "shifts = " << shifts <<endl;
    }
    return 0;
}