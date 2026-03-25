#include<iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,target;
        cin >> n;
        int arr[n];
        for(int i=0 ; i<n ;i++){
            cin >> arr[i];
        }
        cin >> target;
        int prev = 0;
        int curr = 2, count = 0;
        while(curr < n){
            count++;
            if(arr[curr] == target){
                cout<< "Present " << count <<endl ;
                count = -1;
                break ;
            }
            if(arr[curr] > target){
                break;
            }
            prev = curr;
            curr = curr*2;
        }
        prev = prev+1;
        if(count != -1){
            while(prev < n && prev < curr ){
                count++;
                if(arr[prev] == target){
                    cout<< "Present " << count <<endl ;
                    count = -1;
                    break;
                }
                prev++;
            }
        }
        if(count != -1){
            cout<<" Not Present " << count <<endl ;
        }
    }
    return 0;
}