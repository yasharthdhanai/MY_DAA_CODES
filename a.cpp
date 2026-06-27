#include<bits/stdc++.h>
using namespace std;
    
int main(){
    int n ;
    cin >> n ;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++)
        cin >> arr[i];
    
    priority_queue<int> maxHeap;
    for(int i=0 ; i<n ; i++){
        maxHeap.push(arr[i]);
    }

    for(int i=0 ; i<n ; i++){
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    return 0;
}