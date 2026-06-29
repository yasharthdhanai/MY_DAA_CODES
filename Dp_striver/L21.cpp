#include<bits/stdc++.h>
using namespace std;
    
// Target Sum. (Leetcode 494)
class Solution {
public:
    int solve(vector<int>& nums, int target, int idx, vector<vector<int>>& dp){ // recursion + memoization.
        if(idx == 0){
             if(target == 0 && nums[0] == 0)
                return 2;
            if(target == 0 || target == nums[0])
                return 1;
            return 0;
        }

        if(dp[idx][target] != -1)
            return dp[idx][target];
        int NotTake = solve(nums, target, idx-1, dp);
        int Take = 0;
        if(nums[idx] <= target)
            Take = solve(nums, target-nums[idx], idx-1, dp);
        return dp[idx][target] = Take+NotTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        /* It is same as subset sum. We have to make 2 subset whose difference is Target ie. |S1-S2|=Target.
        S2 = Total-S1 so 2*S1-Total=Target. 
        Hence we need to find number of subsets whose sum is Target+Total/2.
        */
        int total=0;
        for(auto x : nums)
            total += x;
        if(abs(target) > total)
            return 0;
        if((target+total)%2 != 0)
            return 0;
        int n = nums.size();
        target = (target+total)/2;
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        return solve(nums, target, n-1, dp);
    }

    int findTargetSumWays2(vector<int>& nums, int target) { // Tabulation
        /* It is same as subset sum. We have to make 2 subset whose difference is Target ie. |S1-S2|=Target.
        S2 = Total-S1 so 2*S1-Total=Target. 
        Hence we need to find number of subsets whose sum is Target+Total/2.
        */
        int total=0;
        for(auto x : nums)
            total += x;
        if(abs(target) > total)
            return 0;
        if((target+total)%2 != 0)
            return 0;
        int n = nums.size();
        target = (target+total)/2;
        vector<vector<int>> dp(n, vector<int> (target+1, 0)); //dp[idx][target]

        // Base Case.
        if(nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;
        for(int i=1; i<=target; i++){ // idx = 0.
            if(i == nums[0])
                dp[0][i] = 1;
            else
                dp[0][i] = 0;
        }

        for(int i=1; i<n; i++){ 
            for(int j=0; j<=target; j++){
                int NotTake = dp[i-1][j];
                int Take = 0;
                if(nums[i] <= j)
                    Take = dp[i-1][j-nums[i]];
                dp[i][j] = Take+NotTake;
            }
        }
        return dp [n-1][target];
    }
};
    
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];
    int Target;
    cin >> Target;
    vector<vector<int>> dp(n, vector<int>(Target+1, -1));
    Solution obj = Solution();
    cout << obj.findTargetSumWays(nums, Target) << endl;
    return 0;
}