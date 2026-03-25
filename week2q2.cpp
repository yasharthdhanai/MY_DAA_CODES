#include<iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n, target;
        cin>>n;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin >> arr[i];
        }
        int x = 0;
        for(int k = n-1 ; k >= 2 ; k--){
            int  i = 0, j = k-1;
            while(i<j){
                if(arr[i] + arr[j] == arr[k]){
                    cout  <<"Sequence : "<< i+1 << ", " << j+1 << ", " << k+1 << endl;
                    x = 1;
                    break;
                }
                else if(arr[i] + arr[j] > arr[k]){
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        if(x == 0)
        cout << "No Sequence Present." << endl;
    }
    return 0;
}