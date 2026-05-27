#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& coins, int i, int sum, vector<vector<int>>& dp){
    // Sum formed
    if(sum == 0){
        return 1;
    }

    // Out of bounds
    if(i >= coins.size()){
        return 0;
    }

    // Invalid sum
    if(sum < 0){  // imp.
        return 0;
    }

    // Already calculated
    if(dp[i][sum] != -1){
        return dp[i][sum];
    }

    // Take coin
    int take = solve(coins, i, sum - coins[i], dp);
    // Skip coin
    int skip = solve(coins, i + 1, sum, dp);
    dp[i][sum] = take + skip;

    return dp[i][sum];
}

int main(){
    int n;
    cout << "Enter number of coins : ";
    cin >> n;
    vector<int> coins(n);

    cout << "Enter coin values : ";
    for(int i=0 ; i<n ; i++){
        cin >> coins[i];
    }

    int sum;
    cout << "Enter target sum : ";
    cin >> sum;

    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));

    int ways = solve(coins, 0, sum, dp);

    cout << "\nNumber of ways = " << ways;

    return 0;
}