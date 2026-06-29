#include<bits/stdc++.h>
using namespace std;
    
// Coin Change 2.(Leetcode 518)
int solve(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp){
    if(amount == 0)
        return 1;
    if(idx == 0){
        if(amount%coins[0] == 0)
            return 1;
        return 0;
    }
    if(dp[idx][amount] != -1)
        return dp[idx][amount];
    int NotTake = solve(idx-1, amount, coins, dp);
    int Take = 0;
    if(amount >= coins[idx])
        Take = solve(idx, amount-coins[idx], coins, dp);
    return dp[idx][amount] = Take+NotTake;
}
int change1(int amount, vector<int>& coins) { // Recursion + Memoization.
    if(amount == 0)
        return 1;
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int> (amount+1, -1));
    return solve(n-1, amount, coins, dp);
}

int change2(int amount, vector<int>& coins) { // Tabulation. 
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int> (amount+1, 0));
    // Base Case.
    for(int i=1; i<=amount; i++){ // idx=0.
        if(i%coins[0] == 0)
            dp[0][i] = 1;
    }
    for(int i=0; i<n; i++)
        dp[i][0] = 1;
    
    for(int idx=1; idx<n; idx++){
        for(int j=1; j<=amount; j++){
            int NotTake = dp[idx-1][j];
            int Take = 0;
            if(j >= coins[idx])
                Take = dp[idx][j-coins[idx]];
            dp[idx][j] = Take+NotTake;
        }
    }
    return dp[n-1][amount];
}
    
int main(){
    
    return 0;
}