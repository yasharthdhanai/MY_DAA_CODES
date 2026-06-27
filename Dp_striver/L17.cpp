#include<bits/stdc++.h>
using namespace std;
    
// Count subsets with sum k.
int CountSubset(vector<int>& nums, int idx, int target){
    if(idx < 0)
        return 0;
    if(target == 0)
        return 1;
    
        int Take = 0;
        if(nums[idx] <= target)
            Take = CountSubset(nums, idx-1, target-nums[idx]);
        int NotTake = CountSubset(nums, idx-1, target);
        return Take + NotTake;
    }

int CountSubset2(vector<int>& nums, int idx, int target, vector<vector<int>>& dp){ // Memoization.
    if(idx < 0)
        return 0;
    if(target == 0)
        return 1;

    if(dp[idx][target] != -1)
        return dp[idx][target];

    int Take = 0;
    if(nums[idx] <= target)
        Take = CountSubset2(nums, idx-1, target-nums[idx], dp);
    int NotTake = CountSubset2(nums, idx-1, target, dp);
    return dp[idx][target] = Take + NotTake;
}

int CountSubset3(vector<int>& nums, int target, vector<vector<int>>& dp){ // Tabulation.
    // dp[n][target] = number of subsets with sum target using first n elements.
    int n = nums.size();
    // Initialize the dp table
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= target; j++){
            if(i == 0)
                dp[i][j] = 0;
            if(j == 0)
                dp[i][j] = 1;
        }
    }

    // Fill the dp table
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= target; j++){
            if(nums[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][target];
}
    
int main(){
    int n ;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    
    int target;
    cin >> target;
    // cout << CountSubset(nums, n-1, target) << endl;
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    cout << CountSubset2(nums, n-1, target, dp) << endl;
    // cout << CountSubset3(nums, target, dp) << endl;
    return 0;
}