#include<bits/stdc++.h>
using namespace std;
    
// Inversion count in an array. if i<j and arr[i]>arr[j] then we got an inversion.
// Similar to merge sort, we will count the inversions while merging the two halves of the array.
// Time complexity: O(nlogn) and space complexity: O(n)
int merge(vector<int>& arr, int st, int mid, int end){
    if(st>=end) 
        return 0;
    vector<int> temp(end-st+1);
    int i = st, j = mid+1, k = 0;
    int count = 0;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]) 
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            count += (mid - i + 1);
        }
    }
    while(i<=mid)
        temp[k++] = arr[i++];
    while(j<=end) 
        temp[k++] = arr[j++];
    for(int i=st; i<=end; i++) 
        arr[i] = temp[i-st];
    return count;
}
int inversionCount(vector<int>& arr, int st, int end){
    if(st>=end) return 0;
    int mid = st + (end-st)/2;
    int l = inversionCount(arr, st, mid);
    int r = inversionCount(arr, mid+1, end);
    return l + r + merge(arr, st, mid, end);
}
    
int main(){
    vector<int> arr = {1, 20, 6, 4, 5, 10, 15, 25, 30, 28};
    int x = inversionCount(arr, 0, arr.size()-1);
    cout << "Inversion count: "<< x << endl;
    return 0;
}