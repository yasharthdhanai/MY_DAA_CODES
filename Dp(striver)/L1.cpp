#include<bits/stdc++.h>
using namespace std;
    
// Fibonachii number. // Time complexity: O(n) for all methords.
int fib1(int n, vector<int> &dp){ // Space complexity: O(n)+O(n) for recursion stack space and dp array.
    if(n <= 1)
        return n;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = fib1(n-1, dp) + fib1(n-2, dp);
    return dp[n];
}

int fib2(int n){ // Space complexity: O(n) for dp array.
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int fib3(int n){ // Space complexity: O(1).
    if(n <= 1)
        return n;

    int prev2 = 0, prev1 = 1, current;
    for(int i=2; i<=n; i++){
        current = prev2 + prev1;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    cout << fib1(n, dp) << endl; // SC = O(n)+O(n) for recursion stack space and dp array.
    cout << fib2(n) << endl; // SC = O(n) for dp array.
    cout << fib3(n) << endl; // SC = O(1).
    return 0;
}