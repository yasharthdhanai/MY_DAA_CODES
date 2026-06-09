#include<bits/stdc++.h>
using namespace std;

// Permutation (Leetcode 46). 
// M1 with extra space as visited array.
void solve(vector<int>& nums, vector<vector<int> >& result, vector<int>& visited, vector<int>& temp){
    if(temp.size() == nums.size()){
        result.push_back(temp);
        return;
    }
    for(int i=0; i<nums.size(); i++){
        if(visited[i] == 0){
            visited[i] = 1;
            temp.push_back(nums[i]);
            solve(nums, result, visited, temp);
            visited[i] = 0;
            temp.pop_back();
        }
    }
    return;
}
vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > result;
    vector<int> temp;
    vector<int> visited(nums.size(), 0);
    solve(nums, result, visited, temp);
    return result;
}
    
int main(){

    return 0;
}