#include<bits/stdc++.h>
using namespace std;

int LCS(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
    // Base Case
    if(i >= s1.size() || j >= s2.size()){
        return 0;
    }

    // Already Calculated
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    // Characters Match
    if(s1[i] == s2[j]){
        dp[i][j] = 1 + LCS(s1, s2, i+1, j+1, dp);
    }

    // Characters Do Not Match
    else{
        dp[i][j] = max(LCS(s1, s2, i+1, j, dp), LCS(s1, s2, i, j+1, dp));
    }

    return dp[i][j];
}

int main(){
    string s1, s2;
    cout << "Sequence1 : ";
    cin >> s1;
    cout << "Sequence2 : ";
    cin >> s2;

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    int length = LCS(s1, s2, 0, 0, dp);

    // Construct LCS String
    string ans = "";

    int i = 0;
    int j = 0;

    while(i < n && j < m){

        // Character matched
        if(s1[i] == s2[j]){

            ans += s1[i];

            i++;
            j++;
        }

        else{

            if(dp[i + 1][j] > dp[i][j + 1]){

                i++;
            }
            else{

                j++;
            }
        }
    }

    cout << "\nLongest Common Subsequence : " << ans;

    cout << "\nLength = " << length;

    return 0;
}