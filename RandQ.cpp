#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
    
int partition(vector<int>& arr, int low, int high){
    int random = low + rand()% (high-low+1);

    swap (arr[high] , arr[random]);
    int i=low , j=low-1;
    int pivot = arr[high];
    while(i<high){
        if(arr[i] <= pivot)
            swap(arr[i], arr[++j]);
        i++;
    }
    swap(arr[i], arr[++j]);
    return j;
}
void quicksort(vector<int>& arr, int low, int high){
    if(low >= high)
        return;
    int p = partition(arr, low, high);
    quicksort(arr, low, p-1);
    quicksort(arr, p+1, high);
    return;
}
    
int main(){

    srand(time(0));

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    quicksort(arr, 0, n-1);
    return 0;
}