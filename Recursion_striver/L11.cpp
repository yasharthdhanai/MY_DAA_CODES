#include<bits/stdc++.h>
using namespace std;
    
// Combinational Sum2 (Leetcode 40).
// Pick and Not Pick Technique.
void solve(vector<int>& candidates, vector<vector<int> > &result, vector<int>& temp, int target, int idx){
    if(target == 0){
        result.push_back(temp);
        return;
    }
    if(idx >= candidates.size())
        return;
    for(int i=idx ; i<candidates.size(); i++){
        if(candidates[i] > target)
            break;
        if(i>idx && candidates[i] == candidates[i-1]) // if idx = 0 so i>idx and.......vdo 29:30.
            continue;
        temp.push_back(candidates[i]);
        solve(candidates, result, temp, target-candidates[i], i+1);
        temp.pop_back();
    }
    return;
}
vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int> > result;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    solve(candidates, result, temp, target, 0); // 0 is index.
    return result;
}
    
int main(){
    
    return 0;
}