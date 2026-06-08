#include<bits/stdc++.h>
using namespace std;
    
//Merge sort.

void MergeArr(vector<int>& arr, int st, int mid, int end){
    if(st>mid || mid+1> end) 
        return;
    if(arr[mid] <= arr[mid+1]) // array is already sorted.
        return;
    int i = st;
    int j = mid+1;
    vector<int> temp;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }
    while(i<=mid)
        temp.push_back(arr[i++]);
    while(j<=end)
        temp.push_back(arr[j++]);
    
    i = st;
    for(auto it : temp){
        arr[i++] = it;
    }
    return;
}


void MergeSort(vector<int>& arr, int st, int end){
    if(st >= end)
        return;
    int mid = (end-st)/2 + st;
    MergeSort(arr, st, mid);
    MergeSort(arr, mid+1, end);
    MergeArr(arr, st, mid, end);
}

int main(){
    vector<int> arr = {3, 1, 2, 4, 1, 5, 2, 6, 4}; // Size = 9
    cout << "Original array is: " << endl;
    for(auto it : arr){
        cout << it << " ";
    }
    MergeSort(arr, 0, 8);
    cout << "\nSorted array is: " << endl;
    for(auto it : arr){
        cout << it << " ";
    }
    return 0;
}