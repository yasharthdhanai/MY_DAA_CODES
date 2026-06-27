#include<bits/stdc++.h>
using namespace std;
    
// Unique Path 2(Leetcode Q.63).
int TotalWays1(vector<vector<int>>& grid, int m, int n){ // M1 by recursion.
    if(m==0 && n==0){
        if(grid[m][n] == 0) // base case.
            return 1;
        else
            return 0;
    }
    if(m<0 || n<0 || grid[m][n] == 1) // base case.
        return 0;
    
    int up = TotalWays1(grid, m-1, n);
    int left = TotalWays1(grid, m, n-1);
    return up + left;
}

int TotalWays2(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp){ // M2 by memoization.
    if(m==0 && n==0){// base case.
        if(grid[m][n] == 0)
            return 1;
        else
            return 0;
    }
    if(m<0 || n<0 || grid[m][n] == 1) // base case.
        return 0;
    
    if(dp[m][n] != -1)
        return dp[m][n];
    
    int up = TotalWays2(grid, m-1, n, dp);
    int left = TotalWays2(grid, m, n-1, dp);
    dp[m][n] = up + left;
    return dp[m][n];
}

int TotalWays3(vector<vector<int>>& grid, int m, int n){ // M3 by Tabulation. (bottom up approach)
    if(grid[0][0] == 1) // if starting point is blocked then we can't move anywhere.
        return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1){
                dp[i][j] = 0;
            }
            else if(i==0 && j==0){
                dp[i][j] = 1;
            }
            else{
                int up = 0, left = 0;
                if(i>0)
                    up = dp[i-1][j];
                if(j>0)
                    left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m-1][n-1];
}

int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    cout << TotalWays1(grid, m-1, n-1) << endl;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << TotalWays2(grid, m-1, n-1, dp) << endl;
    cout << TotalWays3(grid, m, n) << endl;

    return 0;
}