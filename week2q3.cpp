#include<iostream>
using namespace std;

void mergearr(int* arr, int st, int mid, int end){
    int* temp = (int*)malloc((end-st+1)*sizeof(int));
    if (temp == NULL)
        return;
    int i = st, j = mid+1, x = 0 ;
    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            temp[x] = arr[i] ;
            i++ ;
        }
        else{
            temp[x] = arr[j] ;
            j++ ;
        }
        x++ ;
    }
    while(i<=mid){
        temp[x] = arr[i] ;
        i++ ;
        x++ ;
    }
    while(j<=end){
        temp[x] = arr[j] ;
        j++ ;
        x++ ;
    }
    i = st ;
    for (int z=0; z<=end-st ; z++){
        arr[i] = temp[z] ;
        i++ ;
    }
    free(temp);
}
void sortarr(int* arr, int st, int end){ //merge sort
    if(st == end)
        return;
    int mid = (end-st)/2 + st;
    sortarr(arr,st,mid);
    sortarr(arr,mid+1,end);
    mergearr(arr, st, mid, end);
} 

int main(){
    int T;
    cin>>T;
    while(T--){
        int n, k;
        cin>>n;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin >> arr[i];
        }
        sortarr(arr, 0, n-1);
        cin >> k;
        int i=0, j=1, count=0;
        while(j<n){
            if(i == j){
                j++;
                continue;
            }
            if(arr[j]-arr[i] == k){
                count++;
                i++;
                j++;
            }
            else if(arr[j]-arr[i] > k)
                i++;
            else if(arr[j]-arr[i] < k)
                j++;
        }
        cout << count << endl;
    }
    return 0;
}