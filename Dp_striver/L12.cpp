#include<bits/stdc++.h>
using namespace std;
    
// Minimum and Maximum falling path sum (Leetcode Q.931 -> Minimum).

int MinFallingPathSum(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col){
    if(row == matrix.size() - 1){
        dp[row][col] = matrix[row][col];
        return dp[row][col];
    }
    if(col < 0 || col >= matrix.size())
        return 1e9;
    if(dp[row][col] != 1e9)
        return dp[row][col];
    int a = MinFallingPathSum(matrix, dp, row+1, col-1);
    int b = MinFallingPathSum(matrix, dp, row+1, col);
    int c = MinFallingPathSum(matrix, dp, row+1, col+1);
    dp[row][col] = min({a, b, c}) + matrix[row][col];
    return dp[row][col];
}

int MinFallingPathSum2(vector<vector<int>>& matrix) { // Most opt.
    int n = matrix.size();
    vector<int> prev(n, 0); // Base case.
    for(int j=0; j<n; j++){
        prev[j] = matrix[0][j];
    }
    vector<int> curr(n, 0);
    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            int a = matrix[i][j] + prev[j];
            int b = matrix[i][j];
            if(j-1 >= 0) b += prev[j-1];
            else b += 1e9;
            int c = matrix[i][j];
            if(j+1 < n) c += prev[j+1];
            else c += 1e9;
            curr[j] = min({a, b, c});
        }
        prev = curr;
    }
    int ans = 1e9;
    for(int j=0; j<n; j++){
        ans = min(ans, prev[j]);
    }
    return ans;
}       
int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    int ans = MinFallingPathSum(matrix, dp, 0, 0);
    cout << ans << endl;
    return 0;
}