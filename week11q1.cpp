#include<bits/stdc++.h>
using namespace std;

int MCM(vector<int>& arr, int i, int j, vector<vector<int>>& dp){
    if(i == j)
        return 0;

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int mini = INT_MAX;

    for(int k=i ; k<j ; k++){
        int cost = MCM(arr, i, k, dp)+ MCM(arr, k+1, j, dp)+ arr[i-1] * arr[k] * arr[j];
        mini = min(mini, cost);
    }

    dp[i][j] = mini;
    return dp[i][j];
}

int main(){
    int n;
    cin >> n;

    vector<int>mat_size(n+1);

    for(int i=0; i<n+1 ; i++){
        cin >> mat_size[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1)); // dp with all values -1.
    
    int ans = MCM(mat_size, 1, n, dp);
    cout << "\nMinimum multiplication cost = "<< ans;

    // // To store partition position
    // vector<vector<int>> bracket(n+1, vector<int>(n+1, 0));

    // // Length of chain
    // for(int len = 2 ; len <= n ; len++){
    //     for(int i = 1 ; i <= n - len + 1 ; i++){
    //         int j = i + len - 1;
    //         dp[i][j] = INT_MAX;
    //         for(int k = i ; k < j ; k++){
    //             int cost = dp[i][k]+ dp[k+1][j]+ mat_size[i-1] * mat_size[k] * mat_size[j];
    //             if(cost < dp[i][j]){
    //                 dp[i][j] = cost;
    //                 bracket[i][j] = k;
    //             }
    //         }
    //     }
    // }

    return 0;
}