#include<bits/stdc++.h>
using namespace std;
    
// Partition Array Into Two Arrays(of equal length) to Minimize Sum Difference. (Leetcode 2035).
// But YouTube just 2 sub arrays.

int MinimumDifference(vector<int>& nums) { // Using tabulation. (Not for leeetcode, but for YouTube).
    int n = nums.size();
    int Total = 0;
    for(int i=0; i<n; i++)
        Total += nums[i];
    vector<vector<bool>> dp(n, vector<bool>(Total + 1, false));

    // Base Case.
    for(int i=0; i<n; i++)
        dp[i][0] = true;
    if(nums[0] <= Total)
        dp[0][nums[0]] = true;
    
    // Tabulation.
    for(int i=1; i<n; i++){   // index
        for(int j=1; j<=Total; j++){  // target.
            bool NotTake = dp[i-1][j];
            bool Take = false;
            if(nums[i] <= j){
                Take = dp[i-1][j-nums[i]];
            }
            dp[i][j] = Take || NotTake;
        }
    }

    int ans = 1e9;
    for(int i=0; i<=Total/2; i++){
        if(dp[n-1][i]){
            int sum1 = i;
            int sum2 = Total - i;
            int diff = abs(sum1 - sum2);
            ans = min(ans, diff);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans = MinimumDifference(nums);
    cout<<ans<<endl;
    return 0;
}