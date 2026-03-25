#include<bits/stdc++.h>
using namespace std;
    
void heapify(){
    
}
void buildheap(vector<int>& arr, int n){
    for(int i=0 ; i<n ; i++){
        heapify();
    }
}
    
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++)
        cin >> arr[i];

    return 0;
}