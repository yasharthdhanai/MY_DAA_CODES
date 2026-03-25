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
        int low=0, high=n-1, i=0;
        int mid = (high-low)/2+low;
        while(low <= high){
            mid = (high-low)/2+low;
            i++;
            if(target == arr[mid]){
                i=-1;
                break;
            }
            else if(target > arr[mid]){
                low = mid+1;
            }
            else if(target < arr[mid]){
                high = mid-1; 
            }
        }
        if(i != -1)
            cout<<"Not Present." <<endl;
        else{
            int count=1, j=mid;
            while(arr[--j] == target){
                count++;
            }
            j = mid;
            while(arr[++j] == target){
                count++;
            }
            cout<<"Present "<< count << endl;
        }
    }
    return 0;
}