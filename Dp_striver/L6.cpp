#include<bits/stdc++.h>
using namespace std;
   
// House Robber 2. (1st and last are neighbour)
int robLinear(vector<int>& nums, int l, int r) {
    int prev2 = 0;
    int prev1 = 0;

    for(int i=l; i<=r; i++) {
        int cur = max(prev1, nums[i] + prev2);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return nums[0];
    return max(robLinear(nums, 0, n-2), robLinear(nums, 1, n-1));
}
    
int main(){
    int n;
    cin >> n; // (n >= 1)
    vector<int> nums(n);
    for(int i=0; i<n; i++){ // we consider all values to be +ve.
        cin >> nums[i];
    }
    cout << rob(nums) << endl;
    return 0;
}