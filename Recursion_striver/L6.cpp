#include<bits/stdc++.h>
using namespace std;
    
// Print all subsequences.
void printSubsequences(int idx, vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans){
    if(idx >= arr.size()){
        ans.push_back(temp);
        return;
    }
    temp.push_back(arr[idx]);
    printSubsequences(idx+1, arr, temp, ans);
    temp.pop_back();
    printSubsequences(idx+1, arr, temp, ans);
}

void printSubsequences2(int idx, vector<int>& arr, vector<int>& result){
    if(idx >= arr.size()){
        for(auto it : result){
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    result.push_back(arr[idx]);
    printSubsequences2(idx+1, arr, result);
    result.pop_back();
    printSubsequences2(idx+1, arr, result);
}
    
int main(){
    vector<int> arr = {7, 4, 9, 3, 1, 8};
    vector<vector<int>> ans;
    vector<int> temp;
    printSubsequences(0, arr, temp, ans);
    cout << "All subsequences are: " << endl;
    for(auto it: ans){
        for(auto i: it){
            cout << i << " ";
        }
        cout << endl;
    }
    vector<int> result;                
    printSubsequences2(0, arr, result);
    return 0;
}