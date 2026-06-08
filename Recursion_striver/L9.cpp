#include<bits/stdc++.h>
using namespace std;
    
// Quick Sort.
void QuickSort1(vector<int>& arr, int low, int high){ // Pivot is first element.
    if(low >= high)
        return;
    int pivot = low;
    int i = low+1;
    int j = high;
    while(i<j){
        while(i<=high && arr[i] <= arr[pivot])
            i++;
        while(j>low && arr[j] >= arr[pivot])
            j--;
        if(i<j)
            swap(arr[i], arr[j]);
    }
    swap(arr[pivot], arr[j]);
    QuickSort1(arr, low, j-1);
    QuickSort1(arr, j+1, high);
    return;
}

void QuickSort2(vector<int>& arr, int low, int high){ // Last element is pivot.
    if(low >= high)
        return;
    int pivot = high;
    int i = low;
    int j = high-1;
    while(i<j){
        while(i <= high-1 && arr[i] <= arr[pivot])
            i++;
        while(j >= low && arr[j] >= arr[pivot])
            j--;
        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[pivot], arr[i]);
    QuickSort2(arr, low, i-1);
    QuickSort2(arr, i+1, high);
    return;
}    
int main(){
    vector<int> arr = {3, 1, 2, 4, 1, 5, 2, 6, 4}; // Size = 9
    cout << "Original array is: " << endl;
    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;
    QuickSort2(arr, 0, 8);
    cout << "Sorted array is: " << endl;
    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}