#include<bits/stdc++.h>
using namespace std;
    
// Combinational Sum (leetcode 39)
// we will do by pick and not pick technique.

void solve(vector<int>& candidates, vector<vector<int> >& result, vector<int>& temp, int target, int idx){
    if(target == 0){
        result.push_back(temp);
        return;
    }
    if(idx >= candidates.size()){
        return;
    }
    if(candidates[idx] <= target){ // as all elements are +ve.
        temp.push_back(candidates[idx]);
        solve(candidates, result, temp, target-candidates[idx], idx); //remain at same index.
        // solve(candidates, result, temp, target-candidates[idx], idx+1);
        // no need not picking will do this step.
        temp.pop_back();
    }
    solve(candidates, result, temp, target, idx+1);
    return;
}
vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    vector<vector<int> > result;
    vector<int> temp;
    solve(candidates, result, temp, target, 0); // 0 is index.
    return result;
}
    
int main(){
    
    return 0;
}