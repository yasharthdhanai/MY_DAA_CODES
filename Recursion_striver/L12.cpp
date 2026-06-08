#include<bits/stdc++.h>
using namespace std;
    
// Subset I (Leetcode 74).
// We will do it by Pick and Not Pick Technique.
void solve(vector<int>& nums, vector<vector<int> >& result, vector<int>& temp, int idx){
    if(idx == nums.size()){
        result.push_back(temp);
        return;
    }
    temp.push_back(nums[idx]);
    solve(nums, result, temp, idx+1);
    temp.pop_back();
    solve(nums, result, temp, idx+1);
    return;
}
vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> >result;
    vector<int> temp;
    solve(nums, result, temp, 0);
    return result;
}
    
int main(){
    
    return 0;
}