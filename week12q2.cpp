#include<bits/stdc++.h>
using namespace std;

int Knapsack(vector<int>& weight,vector<int>& value, int i, int capacity, vector<vector<int>>& dp){
    // Base Case
    if(i >= weight.size() || capacity == 0){
        return 0;
    }

    // Already Calculated
    if(dp[i][capacity] != -1){
        return dp[i][capacity];
    }

    // Skip Item
    int skip = Knapsack(weight, value, i+1, capacity, dp);

    // Take Item
    int take = 0;

    if(weight[i] <= capacity){
        take = value[i] + Knapsack(weight, value,i + 1, capacity - weight[i], dp);
    }

    dp[i][capacity] = max(take, skip);

    return dp[i][capacity];
}

int main(){

    int n;

    cout << "Enter number of items : ";
    cin >> n;

    vector<int> weight(n);
    vector<int> value(n);

    cout << "Enter weights : ";

    for(int i=0 ; i<n ; i++){

        cin >> weight[i];
    }

    cout << "Enter values : ";

    for(int i=0 ; i<n ; i++){

        cin >> value[i];
    }

    int capacity;

    cout << "Enter knapsack capacity : ";
    cin >> capacity;

    vector<vector<int>> dp(n + 1,
                           vector<int>(capacity + 1, -1));

    int ans =
    Knapsack(weight,
             value,
             0,
             capacity,
             dp);

    cout << "\nMaximum Value = "
         << ans;

    // Find selected items
    vector<int> selectedWeight;
    vector<int> selectedValue;

    int i = 0;
    int currCapacity = capacity;

    while(i < n && currCapacity > 0){

        int skip =
        Knapsack(weight,
                 value,
                 i + 1,
                 currCapacity,
                 dp);

        int take = 0;

        if(weight[i] <= currCapacity){

            take =
            value[i]
            + Knapsack(weight,
                       value,
                       i + 1,
                       currCapacity - weight[i],
                       dp);
        }

        // Item selected
        if(take > skip){

            selectedWeight.push_back(weight[i]);

            selectedValue.push_back(value[i]);

            currCapacity =
            currCapacity - weight[i];
        }
        i++;
    }

    cout << "\nWeights selected : ";
    for(int i=0 ; i<selectedWeight.size() ; i++){
        cout << selectedWeight[i] << " ";
    }

    cout << "\nValues of selected weights : ";
    for(int i=0 ; i<selectedValue.size() ; i++){
        cout << selectedValue[i] << " ";
    }

    return 0;
}