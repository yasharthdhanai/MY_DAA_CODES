#include<bits/stdc++.h>
using namespace std;
    
// Subset Sum == target (Similar to Leetcode 40). 
bool subsetSum(vector<int>& arr, int idx, int target){ // Recursion.
    if(target == 0)
        return true;
    if(idx < 0 || target < 0)
        return false;
    return subsetSum(arr, idx-1, target-arr[idx]) || subsetSum(arr, idx-1, target);
}

bool subsetSum2(vector<int>& arr, int idx, int target, vector<vector<int>>& dp){ // Memoization.
    if(target == 0)
        return true;
    if(idx < 0 || target < 0)
        return false;
    if(dp[target][idx] != -1)
        return dp[target][idx];
    dp[target][idx] = subsetSum(arr, idx-1, target-arr[idx]) || subsetSum(arr, idx-1, target);
    return dp[target][idx];
}

bool subsetSum3(vector<int>& arr, int n, int target){ // Tabulation.
    vector<vector<bool>> dp(target+1, vector<bool>(n, false));

    // Base Case.
    for(int i=0; i<n; i++)
        dp[0][i] = true;

    for(int i=1; i<=target; i++){
        if(arr[0] == i)
            dp[i][0] = true;
    }

    for(int i=1; i<=target; i++){
        for(int j=1; j<n; j++){
            bool notTake = dp[i][j-1];
            bool take = false;
            if(arr[j] <= i)
                take = dp[i-arr[j]][j-1];
            dp[i][j] = take || notTake;
        }
    }
    return dp[target][n-1];
}

bool subsetSum4(vector<int>& arr, int n, int target){ // Space Optimization.
    vector<bool> prev(target+1, false), curr(target+1, false);

    // Base Case.
    prev[0] = curr[0] = true;

    if(arr[0] <= target)
        prev[arr[0]] = true;

    for(int i=1; i<n; i++){
        for(int j=1; j<=target; j++){
            bool notTake = prev[j];
            bool take = false;
            if(arr[i] <= j)
                take = prev[j-arr[i]];
            curr[j] = take || notTake;
        }
        swap(prev, curr); // O(1) instead of copying the entire array which is O(n).
    }
    return prev[target];
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;
    // bool result1 = subsetSum(arr, n-1, target);
    vector<vector<int>> dp(target+1, vector<int>(n, -1));
    bool result2 = subsetSum2(arr, n-1, target, dp); // 0 for false 1 for true.

    cout << (result2 ? "YES" : "NO") << endl;
    return 0;
}