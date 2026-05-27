#include<bits/stdc++.h>
using namespace std;
    
void func(int idx, vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans){
    ans.push_back(temp);
    for(int i = idx; i < arr.size(); i++){
        if(i != idx && arr[i] == arr[idx]) continue;
        temp.push_back(arr[i]);
        func(i + 1, arr, temp, ans);
        temp.pop_back();
    }
}
int main(){
    vector<int> arr = {3, 5, 8, 4, 5, 4};
    vector<int> temp;
    vector<vector<int>> ans;

    func(0, arr, temp, ans);

    for(auto it : ans){
        for(auto i : it){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
