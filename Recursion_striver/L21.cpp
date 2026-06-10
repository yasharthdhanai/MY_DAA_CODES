#include<bits/stdc++.h>
using namespace std;
    
// Kth-Permutation Sequence.

void solve(const vector<int>& factorial, vector<int>& nums, string* ans, int n, int k, int m){ // when m == k we will get the last permutation.
    if((*ans).length() == n) return;
    int x = m;
    int y = (*ans).length();
    for(int i=1; i<=n; i++){
        if(nums[i] == 1) continue;
        x = x+factorial[n-1-y];
        if(x >= k){
            (*ans) = (*ans) + to_string(i-1);
            nums[i-1] = 1;
            solve(factorial, nums, ans, n, k, x);
        }
    }
}

string getPermutation(int n, int k) {
    vector<int> factorial(n+1, 1); // 0! = 1. 
    vector<int> nums(n+1, 0); // to check if the number is used or not. 0 if not used, 1 when used.
    int a = 1;
    for(int i=1; i<=n ;i++){
        a = a*i;
        factorial[i] = a;
    }
    // all factorial are stored in index.
    string ans = "";
    solve(factorial, nums, &ans, n, k, 0); 
    return ans;
}
    
int main(){
    cout << getPermutation(3, 3) << endl;
    return 0;
}