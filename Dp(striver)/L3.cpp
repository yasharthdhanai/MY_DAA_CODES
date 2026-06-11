#include<bits/stdc++.h>
using namespace std;
    
// Frog Jump (Codestudio).
// Concept similar to climbing stairs 2.
int frogJump(int n, vector<int> &heights) { // TC = O(n), SC = O(n).
    vector<int> dp(n, INT_MAX);
    dp[0] = 0; // initially at 0.
    // to reach i th index he has to jump from i-1 or i-2.
    for(int i=1; i<n; i++){
        for(int j=1; j<=2; j++){
            if(i-j<0){
                break;
            }
            int x = dp[i-j] + abs(heights[i] - heights[i-j]);
            if(x<dp[i]){
                dp[i] = x;
            }
        }
    }
    return dp[n-1];
}

int frogJump2(int n, vector<int> &heights) { // TC = O(n), SC = O(1).
    if(n == 1)
        return 0;

    int prev1 = abs(heights[1]-heights[0]); // 1st prev.
    int prev2 = 0; // 2nd prev.
    int current = -1;

    for(int i=2; i<n; i++){
        current = min(prev1+ abs(heights[i]-heights[i-1]) , prev2+ abs(heights[i]-heights[i-2]));
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}
    
int main(){
    int n;
    cin >> n; // (n >= 1)
    vector<int> heights(n);
    for(int i=0; i<n; i++){
        cin >> heights[i];
    }
    cout << frogJump(n, heights) << endl;
    cout << frogJump2(n, heights) << endl;
    return 0;
}