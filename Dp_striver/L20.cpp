#include<bits/stdc++.h>
using namespace std;
    
// Minimum Coins Problem.
// Infinite supply of each coin denomination.
int MinCoins(vector<int> &coins, int Target, int idx){ // Recursion.
    if(Target == 0)
        return 0;
    if(idx == 0){
        if(Target % coins[0] == 0)
            return Target / coins[0];
        return 1e9;
    }
    
    int NotTake = MinCoins(coins, Target, idx-1);
    int Take = INT_MAX;
    if(coins[idx] <= Target)
        Take = MinCoins(coins, Target-coins[idx], idx)+1;
    return min(NotTake, Take);
}

int MinCoins2(vector<int> &coins, int Target, int idx, vector<vector<int>> &dp){ // Memoization.
    if(Target == 0)
        return 0;
    if(idx == 0){
        if(Target % coins[0] == 0)
            return Target / coins[0];
        return 1e9;
    }
    
    if(dp[idx][Target] != -1) // dp[idx][Target].
        return dp[idx][Target];
    
    int NotTake = MinCoins2(coins, Target, idx-1, dp);
    int Take = INT_MAX;
    if(coins[idx] <= Target)
        Take = MinCoins2(coins, Target-coins[idx], idx, dp)+1;
    return dp[idx][Target] = min(NotTake, Take);
}

int MinCoins3(vector<int> &coins, int Target, vector<vector<int>> &dp){ // Tabulation.
    // Base Case.
    int n = coins.size();
    for(int i=0; i<n; i++) // Target is 0 at diffrent index.
        dp[i][0] = 0;
    
    for(int i=1; i<=Target; i++){ // Idx is 0 for diffrent target
        if(i % coins[0] == 0)
            dp[0][i] = i / coins[0];
        else
            dp[0][i] = 1e9;
    }
    // dp[idx][Target].
    for(int i=1; i<n; i++){
        for(int j=1; j<=Target; j++){
            int NotTake = dp[i-1][j];
            int Take = 1e9;
            if(coins[i] <= j)
                Take = dp[i][j-coins[i]]+1;
            dp[i][j] = min(Take, NotTake); 
        }
    }
    if(dp[n-1][Target] >= 1e9)
        return -1;
    return dp[n-1][Target];
}

int MinCoins4(vector<int> &coins, int Target){ // Space Optimize.
    int n = coins.size();
    vector<int> curr(Target+1, 0), prev(Target+1, 0);

    // Base Case.
    for(int i=0; i<=Target; i++){ // Idx is 0 for diffrent target
        if(i % coins[0] == 0)
            prev[i] = i / coins[0];
        else
            prev[i] = 1e9;
    }
    
    for(int i=1; i<n; i++){
        curr[0] = 0;
        for(int j=1; j<=Target; j++){
            int NotTake = prev[j];
            int Take = INT_MAX;
            if(coins[i] <= j)
                Take = curr[j-coins[i]]+1;
            curr[j] = min(Take, NotTake); 
        }
        prev = curr;
    }

    if(prev[Target] >= 1e9)
        return -1;
    return prev[Target];
}

int main(){
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i=0; i<n; i++)
        cin >> coins[i];
    int Target;
    cin >> Target;
    vector<vector<int>> dp(n, vector<int>(Target+1, -1));

    int a = MinCoins(coins, Target, n-1);
    if(a >= 1e9)
        cout << -1 << endl;
    else cout << a << endl;

    int b = MinCoins2(coins, Target, n-1, dp);
    if(b >= 1e9)
        cout << -1 << endl;
    else cout << b << endl;

    int c = MinCoins3(coins, Target, dp);
    cout << c << endl;
    return 0;
}