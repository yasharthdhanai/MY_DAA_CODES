#include<bits/stdc++.h>
using namespace std;
    
// Cherry Pickup I (Leetcode Q.741).
    
int solve(int i1, int i2, int j1, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){ // Memoization.
    int j2 = i1 + j1 - i2;
    int n = grid.size();

    // Base Case.
    if(i1 >= n || i2 >= n || j1 >= n || j2 >= n) // Out of Bound.
        return -1e8;
    if(grid[i1][j1] == -1 || grid[i2][j2] == -1) // Blocked Path.
        return -1e8;
    if(i1 == n-1 && j1 == n-1) // Destination .
        return grid[i1][j1];

    if(dp[i1][i2][j1] != -1)
        return dp[i1][i2][j1];

    // i1, i2, j1
    int a = solve(i1+1, i2, j1, grid, dp);
    int b = solve(i1+1, i2+1, j1, grid, dp);
    int c = solve(i1, i2, j1+1, grid, dp);
    int d = solve(i1, i2+1, j1+1, grid, dp);
    
    if(i1 == i2 && j1 == j2)
        dp[i1][i2][j1] = max({a, b, c, d}) + grid[i1][j1];
    else
        dp[i1][i2][j1] = max({a, b, c, d}) + grid[i1][j1] + grid[i2][j2];
    return dp[i1][i2][j1];
}

int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1e8)));

    // We assume 2 persons at (0,0) so at a particular time they travelled same distance.
    // i1 + j1 = i2 + j2.
    // return max(solve(0, 0, 0, grid, dp), 0); // we are passing i1, i2, j1.

    dp[n-1][n-1][n-1] = grid[n-1][n-1]; // Base Case.
    
    for(int i1=n-1; i1>=0 ; i1--){ // Tabulation.
        for(int j1=n-1; j1>=0; j1--){
            for(int i2=n-1; i2>=0; i2--){
                if(i1 == n-1 && i2 == n-1 && j1 == n-1)
                    continue;
                int j2 = i1+j1-i2;
                if(j2<0 || j2>=n){
                    continue;
                }
                if(grid[i1][j1] == -1 || grid[i2][j2] == -1)
                    continue;
                int a=-1e8, b=-1e8, c=-1e8, d=-1e8;
                if(i1+1<n)
                    a = dp[i1+1][i2][j1];
                if(i1+1<n && i2+1<n)
                    b = dp[i1+1][i2+1][j1];
                if(j1+1<n)
                    c = dp[i1][i2][j1+1];
                if(i2+1<n && j1+1<n)
                    d = dp[i1][i2+1][j1+1];
                
                if(i1 == i2) // j2 == j1 (because i1+j1 = i2+j2)
                    dp[i1][i2][j1] = max({a, b, c, d}) + grid[i1][j1];
                else
                    dp[i1][i2][j1] = max({a, b, c, d}) + grid[i1][j1] + grid[i2][j2];
            }
        }
    }
    return max(dp[0][0][0], 0);
}
int main(){
    
    return 0;
}