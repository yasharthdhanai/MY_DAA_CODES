#include<bits/stdc++.h>
using namespace std;
    
// Maximum sum of non adjacent elements.
// House Robber 1.
int MaxProfit(vector<int>& arr){
    if(arr.size() == 1)
        return arr[0];
    int prev1 = max(arr[0], arr[1]);
    int prev2 = arr[0];
    int current = 0;

    for(int i=2; i<arr.size(); i++){
        current = max(arr[i]+prev2, prev1);
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}
    
int main(){
    int n;
    cin >> n; // (n >= 1)
    vector<int> arr(n);
    for(int i=0; i<n; i++){ // we consider all values to be +ve.
        cin >> arr[i];
    }
    cout << MaxProfit(arr) << endl;
    return 0;
}