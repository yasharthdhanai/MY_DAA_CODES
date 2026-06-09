#include<bits/stdc++.h>
using namespace std;

// Permutation (Leetcode 46).
// M2 - By swapping multiple times we get permutaions.

void solve(vector<int>& nums, vector<vector<int> >& result, int idx){
    if(idx == nums.size()){
        result.push_back(nums);
    }
    for(int i=idx; i<nums.size() ; i++){
        swap(nums[idx], nums[i]);
        solve(nums, result, idx+1);
        swap(nums[idx], nums[i]);
    }
    return;
}
vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > result;
    solve(nums, result, 0);
    return result;
}
    
int main(){

    return 0;
}