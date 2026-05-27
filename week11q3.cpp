#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>& arr, int i, int target, vector<vector<int>>& dp){
    // Target achieved
    if(target == 0){
        return true;
    }

    // Out of bounds
    if(i >= arr.size()){
        return false;
    }

    // Invalid target
    if(target < 0){
        return false;
    }

    // Already calculated
    if(dp[i][target] != -1){
        return dp[i][target];
    }

    // Take element
    bool take = solve(arr, i + 1, target - arr[i], dp);
    // Skip element
    bool skip = solve(arr, i + 1, target, dp);

    dp[i][target] = take || skip;

    return dp[i][target];
}

int main(){
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter elements : ";
    int total = 0;
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
        total += arr[i];
    }

    // If sum is odd
    if(total % 2 != 0){
        cout << "\nNo";
        return 0;
    }

    int target = total / 2;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    bool ans = solve(arr, 0, target, dp);

    if(ans){
        cout << "\nYes";
    }
    else{
        cout << "\nNo";
    }

    return 0;
}