#include<bits/stdc++.h>
using namespace std;
    
// 0/1 Knapsack Problem.
int MaxProfit(vector<int>& weight, vector<int>& value, int capacity, int idx) { // Recursion (Pick / Not Pick)
    // Base Case.
    if(idx < 0 || capacity == 0)
        return 0;

    int NotPick = MaxProfit(weight, value, capacity, idx-1) ;
    int Pick = INT_MIN;
    if(capacity >= weight[idx])
        Pick = MaxProfit(weight, value, capacity-weight[idx], idx-1) + value[idx];

    return max(Pick, NotPick);
}

int MaxProfit2(vector<int>&weight, vector<int>&value, int capacity, int idx, vector<vector<int>>&dp){ // Memoization.
    if(idx < 0 || capacity == 0)
        return 0;
    
    if(dp[idx][capacity] != -1){  // dp[idx][capacity]
        return dp[idx][capacity];
    }
    int NotPick = MaxProfit2(weight, value, capacity, idx-1, dp) ;
    int Pick = INT_MIN;
    if(capacity >= weight[idx])
        Pick = MaxProfit2(weight, value, capacity-weight[idx], idx-1, dp) + value[idx];

    return dp[idx][capacity] = max(Pick, NotPick); 
}

int MaxProfit3(vector<int>&weight, vector<int>&value, int capacity, int idx, vector<vector<int>>&dp){ // Tabulation.
    int n = weight.size();
    // Base Case
    for(int i=0; i<n ; i++){ // dp[idx][capacity] -> Max Profit.
        dp[i][0] = 0;
    }
    for(int i=0; i<=capacity; i++){
        if(weight[0] <= i)
            dp[0][i] = value[0];
        else  
            dp[0][i] = 0;
    }

    for(int i=1; i<n; i++){ // idx
        for(int j=0; j<=capacity; j++){ // capacity.
            int NotPick = dp[i-1][j];
            int Pick = INT_MIN;
            if(j >= weight[i])
                Pick = dp[i-1][j-weight[i]] + value[i];
            dp[i][j] = max(Pick, NotPick);
        }
    }
    return dp[n-1][capacity];
}

// In tabulation we see for calculation ith row we need i-1 row only.
// So we can use 2 rows only (prev, curr) instead of n rows.

int MaxProfit4(vector<int>&weight, vector<int>&value, int capacity, int idx){ // Space Optimization.
    int n = weight.size();
    vector<int> prev(capacity+1, 0), curr(capacity+1, 0); // 2 vectors of size capacity+1.
    // Base Case
    for(int i=0; i<=capacity; i++){
        if(weight[0] <= i)
            prev[i] = value[0];
        else  
            prev[i] = 0;
    }

    for(int i=1; i<n; i++){ // idx
        for(int j=0; j<=capacity; j++){ // capacity.
            int NotPick = prev[j];
            int Pick = INT_MIN;
            if(j >= weight[i])
                Pick = prev[j-weight[i]] + value[i];
            curr[j] = max(Pick, NotPick);
        }
        swap(prev, curr);
    }
    return prev[capacity];
}

// In Pick line we see we are using only j-weight[i] column of prev row.
// So we can use 1D array instead of 2D array, if we traverse j from capacity to 0. (ie in reverse order)

int MaxProfit5(vector<int>&weight, vector<int>&value, int capacity, int idx){ // Space Optimization.
    int n = weight.size();
    vector<int> prev(capacity+1, 0); // 1 vector of size capacity+1.
    // Base Case
    for(int i=0; i<=capacity; i++){
        if(weight[0] <= i)
            prev[i] = value[0];
        else  
            prev[i] = 0;
    }

    for(int i=1; i<n; i++){ // idx
        for(int j=capacity; j>=0; j--){ // capacity.
            int NotPick = prev[j];
            int Pick = INT_MIN;
            if(j >= weight[i])
                Pick = prev[j-weight[i]] + value[i];
            prev[j] = max(Pick, NotPick);
        }
    }
    return prev[capacity];
}
int main(){
    int n;
    cin >> n;
    vector<int> weight(n), value(n);
    for(int i=0 ; i<n ; i++)
        cin >> weight[i];
    for(int i=0 ; i<n ; i++)
        cin >> value[i];
    int capacity;
    cin >> capacity;
    // cout << MaxProfit(weight, value, capacity, n-1) << endl;
    vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
    // cout << MaxProfit2(weight, value, capacity, n-1, dp) << endl;
    cout << MaxProfit3(weight, value, capacity, n-1, dp) << endl;
    return 0;
}