#include<bits/stdc++.h>
using namespace std;
    
int func(int idx1, int idx2, string& s1, string& s2, vector<vector<int>>& dp){
    if(idx1 == s1.length() || idx2 == s2.length()){
        return 0;
    }
    if(dp[idx1][idx2] != -1){
        return dp[idx1][idx2];
    }
    
    if(s1[idx1] == s2[idx2]){
        int x = func(idx1+1, idx2+1, s1, s2, dp) + 1;
        dp[idx1][idx2] = x;
        return x;
    }
    int a = func(idx1+1, idx2, s1, s2, dp);
    int b = func(idx1, idx2+1, s1, s2, dp);
    if(a>b){
        dp[idx1][idx2] = a;
        return a;
    }
    dp[idx1][idx2] = b;
    return b;
}
int main(){
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;

// 1st way is by making subsequence of each string like subset then check but time complexity v.high
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m , vector<int>(n, -1)); // 2d vector with initial value -1

    int l = func(0 , 0, s1, s2, dp);

    cout << "longest subsequence length : " << l <<"\n"; 

    string subseq = "";
    int i = 0, j = 0;
    while(i < m && j < n){
        if(s1[i] == s2[j]){
            subseq += s1[i];
            i++;
            j++;
        }
        else{
            // make sure dp values exist
            int down = func(i+1, j, s1, s2, dp);
            int right = func(i, j+1, s1, s2, dp);

            if(down > right){
                i++;
            } else {
                j++;
            }
        }
    }

    cout << "subsequence : " << subseq << "\n";

    for(int i=0 ; i<m ; i++){
        for(int j=0; j<n ;j++){
            cout<< dp[i][j];
        }
        cout<< "\n";
    }

    return 0;
}