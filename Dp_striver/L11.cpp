#include<bits/stdc++.h>
using namespace std;
    
// Triangle(Leetcode Q.120).
// M1 : Recursion + Memoization -> Space Complexity : O(n^2)+O(n) and Time Complexity : O(n^2)
int solve(vector<vector<int>>& triangle, vector<vector<int>>& dp, int row, int col){
    if(row == triangle.size() - 1){
        dp[row][col] = triangle[row][col];
        return dp[row][col];
    }
    if(col > row)
        return 1e9;
    if(dp[row][col] != 1e9)
        return dp[row][col];
    int a = solve(triangle, dp, row+1, col);
    int b = solve(triangle, dp, row+1, col+1);
    dp[row][col] = min(a, b) + triangle[row][col];
    return dp[row][col];
}

// M2 : Tabulation -> Space Complexity : O(n^2) and Time Complexity : O(n^2)
int solve2(vector<vector<int>>& triangle, vector<vector<int>>& dp){
    int n = triangle.size();
    for(int j=0; j<n; j++)          // Base case
        dp[n-1][j] = triangle[n-1][j];
    
    for(int i=n-2; i>=0; i--){
        for(int j=0; j<=i; j++){
            int a = dp[i+1][j];
            int b = dp[i+1][j+1];
            dp[i][j] = min(a, b) + triangle[i][j];
        }
    }
    return dp[0][0];
}

// M3 : Space Optimization -> Space Complexity : O(n) and Time Complexity : O(n^2)
int solve3(vector<vector<int>>& triangle){
    int n = triangle.size();
    vector<int> prev(n, 1e9);
    vector<int> curr(n, 1e9);

    for(int j=0; j<n; j++)          // Base case
        prev[j] = triangle[n-1][j];
    
    for(int i=n-2; i>=0; i--){
        for(int j=0; j<=i; j++){
            int a = prev[j];
            int b = prev[j+1];
            curr[j] = min(a, b) + triangle[i][j];
        }
        prev = curr;
    }
    return prev[0];
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    return solve(triangle, dp, 0, 0);
}

int main(){
    
    
    return 0;
}