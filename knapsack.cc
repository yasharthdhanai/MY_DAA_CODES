#include<bits/stdc++.h>
using namespace std;

int func(int idx, vector<int>& weight, vector<int>& value, int capacity, vector<vector<int>>& dp){
    if(idx >= weight.size() || capacity == 0){
        return 0;
    }
    if(dp[idx][capacity] != -1){
        return dp[idx][capacity];
    }
    int take = 0;
    if(weight[idx] <= capacity){
        take = value[idx] + func(idx +1, weight, value, capacity-weight[idx], dp);
    }
    int not_take = func(idx +1, weight, value, capacity, dp);
    if(take > not_take){
        dp[idx][capacity] = take;
        return take;
    }
    dp[idx][capacity] = not_take;
    return not_take;
}
    
int main(){
    int n;
    cin >> n;
    vector<int> value;
    int m = 0;
    while(m < n){
        int x;
        cin >> x;
        value.push_back(x);
        m++;
    }

    vector<int> weight;
    m = 0;
    while(m < n){
        int x;
        cin >> x;
        weight.push_back(x);
        m++;
    }

    
    int capacity;
    cin >> capacity;

    vector<vector<int>> dp(m , vector<int>(capacity+1, -1));

    int maxval = func(0, weight, value, capacity, dp);
    cout << "Maximum Value : " << maxval << endl;

    return 0;
}