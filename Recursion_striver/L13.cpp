#include<bits/stdc++.h>
using namespace std;
    
// Concept same as combinational sum 2 (leetcode 40).
void solve(vector<int>& nums, vector<vector<int> >& result, vector<int>& temp, int idx){
    result.push_back(temp);
    for(int i=idx; i<nums.size(); i++){
        if(i>idx && nums[i] == nums[i-1])
            continue;
        temp.push_back(nums[i]);
        solve(nums, result, temp, i+1);
        temp.pop_back();
    }
    return;
}
vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > result;
    vector<int> temp;
    solve(nums, result, temp, 0);
    return result;
}
 
int main(){
    
    return 0;
}