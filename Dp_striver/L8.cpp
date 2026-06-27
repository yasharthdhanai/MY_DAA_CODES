#include<bits/stdc++.h>
using namespace std;
    
// Unique Paths 1.(Leetcode Q.62)
int Totalways1(int m, int n){ // M1 by recursion.
    if(m==0 || n==0) // base case.
        return 1;
    if(m<0 || n<0) // base case.
        return 0;
    
    int up = Totalways1(m-1, n);
    int left = Totalways1(m, n-1);
    return up + left;
}

int Totalways2(int m, int n, vector<vector<int>>& dp){ // M2 by memoization.
    if(m==0 || n==0) // base case.
        return 1;
    if(m<0 || n<0) // base case.
        return 0;
    
    if(dp[m][n] != -1)
        return dp[m][n];
    
    int up = Totalways2(m-1, n, dp);
    int left = Totalways2(m, n-1, dp);
    dp[m][n] = up + left;
    return dp[m][n];
}
int Totalways3(int m, int n){ // M3 by Tabulation.
    vector<vector<int>> dp(m , vector<int>(n, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 || j==0)
                dp[i][j] = 1; // Base Cases.
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
    
int main(){
    int m,n;
    cin >> m >> n;
    cout << Totalways1(m, n) << endl;
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    cout << Totalways2(m, n, dp) << endl;
    cout << Totalways3(m, n) << endl;
    return 0;
}