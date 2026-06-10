#include<bits/stdc++.h>
using namespace std;
    
// Rat in a Maze.
// u are at (0,0) and you have to reach (n-1,n-1). order->D/L/R/U
// you can move only where is 1 in matrix, 0 is blocked way. evernode should be visited at max 1.

void solve(vector<vector<int>>& grid, int i, int j, string s){
    int n = grid.size();
    if(i == n-1 && j == n-1){
        cout << s << endl;
        return;
    }

    // order->D/L/R/U
    if(i<n-1 && 1 == grid[i+1][j]){ // for Down.
        grid[i+1][j] = 0;
        solve(grid, i+1, j, s+"D");
        grid[i+1][j] = 1;
    }

    if(j != 0 && 1 == grid[i][j-1]){ // for Left.
        grid[i][j-1] = 0;
        solve(grid, i, j-1, s+"L");
        grid[i][j-1] = 1;
    }

    if(j<n-1 && 1 == grid[i][j+1]){ // for Right.
        grid[i][j+1] = 0;
        solve(grid, i, j+1, s+"R");
        grid[i][j+1] = 1;
    }

    if(i != 0 && 1 == grid[i-1][j]){ // for Up.
        grid[i-1][j] = 0;
        solve(grid, i-1, j, s+"U");
        grid[i-1][j] = 1;
    }
    return;
}

void findpath(vector<vector<int>> grid){ // size of grid n*n.
    if(grid[0][0] == 0) return;
    grid[0][0] = 0;
    solve(grid, 0, 0, "");
}

int main(){
    
    return 0;
}