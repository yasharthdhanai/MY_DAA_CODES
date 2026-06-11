#include<bits/stdc++.h>
using namespace std;

// Climbing Stairs (Leetcode 70). Time complexity: O(n) and Space complexity: O(1).
// Same logic as Fibonachii number.

int climbStairs(int n) {
    if(n <= 2){
        return n;
    }
    int prev2 = 1;
    int prev1 = 2;
    int current = 0;
    for(int i=3; i<=n ; i++){
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}
    
int main(){
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;
    return 0;
}