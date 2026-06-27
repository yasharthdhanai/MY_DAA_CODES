#include<bits/stdc++.h>
using namespace std;
    
// Minimum Path Sum in a grid(Leetcode Q.64).
int MinPathSum1(vector<vector<int>>& grid, int m, int n){ // M1 by recursion.
    if(m==0 && n==0) // base case.
        return grid[m][n];
    if(m<0 || n<0) // base case.
        return INT_MAX;
    
    int up = grid[m][n] + MinPathSum1(grid, m-1, n);
    int left = grid[m][n] + MinPathSum1(grid, m, n-1);
    return min(up, left);
}

int MinPathSum2(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp){ // M2 by memoization.
    if(m==0 && n==0) // base case.
        return grid[m][n];
    if(m<0 || n<0) // base case.
        return INT_MAX;
    
    if(dp[m][n] != INT_MAX)
        return dp[m][n];
    
    int up = grid[m][n] + MinPathSum2(grid, m-1, n, dp);
    int left = grid[m][n] + MinPathSum2(grid, m, n-1, dp);
    dp[m][n] = min(up, left);
    return dp[m][n];
}

int MinPathSum3(vector<vector<int>>& grid, int m, int n){ // M3 by Tabulation. (bottom up approach)
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                dp[i][j] = grid[i][j];
                continue;
            }
            int up = INT_MAX, left = INT_MAX;
            if(i>0)
                up = grid[i][j] + dp[i-1][j];
            if(j>0)
                left = grid[i][j] + dp[i][j-1];
            dp[i][j] = min(up, left);
        }
    }
    return dp[m-1][n-1];
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    cout << MinPathSum1(grid, m-1, n-1) << endl;
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    cout << MinPathSum2(grid, m-1, n-1, dp) << endl;
    cout << MinPathSum3(grid, m, n) << endl;
    return 0;
}