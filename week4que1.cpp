#include<iostream>
#include<vector>
using namespace std;

int com = 0, inv = 0;

void mergearr(vector<int>& arr, int st, int mid, int end){
    vector<int> temp;
    int i = st, j = mid + 1;

    while(i <= mid && j <= end){
        com++;
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
            inv += (mid - i + 1);
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int k = 0; k < temp.size(); k++){
        arr[st + k] = temp[k];
    }
}

void sortarr(vector<int>& arr, int st, int end){
    if(st >= end)
        return;
    int mid = st + (end - st)/2;
    sortarr(arr, st, mid);
    sortarr(arr, mid+1, end);
    mergearr(arr, st, mid, end);
}

int main(){
    int T, n;
    cin >> T;
    while(T--){
        cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++)
            cin >> arr[i];

        sortarr(arr, 0, n-1);

        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
        cout << "comparisons : " << com << endl;
        cout << "inversions : " << inv << endl;

        com = 0;
        inv = 0;
    }
}