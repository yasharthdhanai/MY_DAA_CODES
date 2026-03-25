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
        cin >> target;
        int i=0;
        for(i; i<n ; i++){
            if(arr[i] == target){
                cout <<"Present " << i+1 << endl;
                break;
            }
        }
        if(i == n)
            cout <<"Not Present " << i << endl;
    }
    return 0;
}