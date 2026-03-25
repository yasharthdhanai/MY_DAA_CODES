#include<iostream>
#include<vector>

using namespace std;

void mergearr(vector<int>& arr, int st, int mid, int end){
    int i = st, j = mid+1, x = 0;
    vector<int> temp(end - st + 1);
    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            temp[x] = arr[i] ;
            i++ ;
        }
        else{
            temp[x] = arr[j] ;
            j++ ;
        }
        x++;
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
}

void sortarr(vector<int>& arr, int st, int end){
    if(st>=end)
        return;
    int mid = (end-st)/2 + st;
    sortarr(arr, st, mid);
    sortarr(arr, mid+1, end);
    mergearr(arr, st, mid, end);
}

int main(){
    int T, n, target;
    cin >> T;
    while(T--){
        cin >> n;
        vector<int> arr(n);
        for(int i=0 ; i<n ; i++){
            cin >> arr[i];
        }
        sortarr(arr, 0, n-1);
        cin >> target;
        int i = 0, j = n-1;
        while(i<j){
            if(arr[i] + arr[j] == target){
                cout << "Ans = " << arr[i] << " " << arr[j] << endl;
                i = -1;
                break;
            }
            else if(arr[i] + arr[j] > target)
                j--;
            else
                i++;
        }
        if(i != -1)
            cout << "No Such Elements Exist.\n";
    }
    return 0;
}