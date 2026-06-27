#include<bits/stdc++.h>
using namespace std;
    
// Cherry Pickup II (Leetcode Q.1463).
int cherryPickupSolve1(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){ // Memoization.
    int rows = grid.size();
    int cols = grid[0].size();
    if(j1<0 || j2<0 || j1>=cols || j2>=cols) // Out of Bound Base Case.
        return -1e9;
    if(i == rows-1){  // Base case for reaching destination.
        if(j1 == j2)
            return grid[i][j1];
        return grid[i][j1] + grid[i][j2];
    }
    
    if(dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int maxi = 0;
    for(int a=-1; a<=1; a++){
        for(int b=-1; b<=1; b++){
            if(j1 == j2)
                maxi = max(grid[i][j1] + cherryPickupSolve1(i+1, j1+a, j2+b, grid, dp), maxi);
            else
                maxi = max(grid[i][j1] + grid[i][j2] + cherryPickupSolve1(i+1, j1+a, j2+b, grid, dp), maxi);
        }
    }
    dp[i][j1][j2] = maxi;
    return dp[i][j1][j2];
}

int cherryPickupSolve2(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){ //  Tabulation.
    // Reduces Stack Space.
    int rows = grid.size();
    int cols = grid[0].size();

    // Base case.
    for(int j1=0; j1<cols; j1++){
        for(int j2=0; j2<cols; j2++){
            if(j1 == j2)
                dp[rows-1][j1][j2] = grid[rows-1][j1];
            else
                dp[rows-1][j1][j2] = grid[rows-1][j1] + grid[rows-1][j2];
        }
    }

    for(int i=rows-2; i>=0; i--){
        for(int j1=0; j1<cols; j1++){
            for(int j2=0; j2<cols; j2++){
                // Same as Memoization.
                int maxi = -1e9;;
                for(int a=-1; a<=1; a++){
                    for(int b=-1; b<=1; b++){
                        int value = 0;
                        if(j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if(j1+a >= 0 && j1+a < cols && j2+b >= 0 && j2+b < cols)
                            value += dp[i+1][j1+a][j2+b];
                        else
                            value += -1e9;
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][cols-1]; // Starting pos of Rob1 and Rob2.
}

// Space Optimization.
// 1D DP -> 2 variables.
// 2D DP -> 1 variable.
// 3D DP -> 2 variables.
int cherryPickupSolve3(vector<vector<int>>& grid){ // Space Optimization.
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> front(cols, vector<int>(cols, 0));
    vector<vector<int>> curr(cols, vector<int>(cols, 0));

    // Base case.
    for(int j1=0; j1<cols; j1++){
        for(int j2=0; j2<cols; j2++){
            if(j1 == j2)
                front[j1][j2] = grid[rows-1][j1];
            else
                front[j1][j2] = grid[rows-1][j1] + grid[rows-1][j2];
        }
    }

    for(int i=rows-2; i>=0; i--){
        for(int j1=0; j1<cols; j1++){
            for(int j2=0; j2<cols; j2++){
                // Same as Memoization.
                int maxi = -1e9;;
                for(int a=-1; a<=1; a++){
                    for(int b=-1; b<=1; b++){
                        int value = 0;
                        if(j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if(j1+a >= 0 && j1+a < cols && j2+b >= 0 && j2+b < cols)
                            value += front[j1+a][j2+b];
                        else
                            value += -1e9;
                        maxi = max(maxi, value);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        // front = curr; if we do this, we will be copying the entire 2D array which is O(n). 
        // Instead, we can just swap the two arrays O(1).
        swap(front, curr);
    }
    return front[0][cols-1];
}

    
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    // dp[i][j][j].
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    // cout << cherryPickupSolve1(0, 0, m-1, grid, dp); // Staring pos of Rob1 and Rob2.
    // cout << cherryPickupSolve2(0, 0, m-1, grid, dp);
    cout << cherryPickupSolve3(grid); // Staring pos of Rob1 and Rob2.
    return 0;
}