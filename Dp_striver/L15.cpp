#include<bits/stdc++.h>
using namespace std;
    
// Partition Equal Subset Sum. (Leetcode 416).
bool canPartition(vector<int>& arr, int target, vector<vector<int>>& dp, int n){ // Memoization.
    if(target == 0) return true;
    if(n < 0 || target < 0) return false;

    if(dp[n][target] != -1) return dp[n][target];

    return dp[n][target] = canPartition(arr, target-arr[n-1], dp, n-1) || canPartition(arr, target, dp, n-1);  
}

bool canPartition2(vector<int>& arr, int target, int n){ // Tabulation.
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // Base Case.
    for(int i=0; i<n; i++)
        dp[i][0] = true;
    for(int i=0; i<=target; i++){
        if(arr[0] == i)
            dp[0][i] = true;
    }

    // Filling the dp array.
    for(int i=1; i<n; i++){   // index
        for(int j=1; j<=target; j++){  // target.
            bool NotTake = dp[i-1][j];
            bool Take = false;
            if(arr[i] <= j){
                Take = dp[i-1][j-arr[i]];
            }
            dp[i][j] = Take || NotTake;
        }
    }
    return dp[n-1][target];
}

bool canPartition3(vector<int>& nums, int target, int n){ // Space Optimization.
    vector<bool> prev(target + 1, false);
    vector<bool> curr(target + 1, false);

    // Base Case.
    prev[0] = curr[0] = true;
    if(nums[0] <= target)
        prev[nums[0]] = true;

    for(int i=1; i<n; i++){
        for(int j=1; j<=target; j++){
            bool NotTake = prev[j];
            bool Take = false;
            if(nums[i] <= j){
                Take = prev[j-nums[i]];
            }
            curr[j] = Take || NotTake;
        }
        if(curr[target]) // Early Exit.
            return true;
        swap(prev, curr);
    }
    return prev[target];   
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int target;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        target += arr[i];
    }
    if(target%2 != 0){
        cout << "No" ;
        return 0;
    }
    vector<vector<int>> dp(n + 1, vector<int>(target/2 + 1, -1));
    bool result = canPartition(arr, target/2, dp, n);
    cout << (result ? "YES" : "NO") << endl;
    return 0;
}