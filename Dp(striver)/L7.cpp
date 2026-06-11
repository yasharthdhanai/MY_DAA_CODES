#include<bits/stdc++.h>
using namespace std;
    
// Ninja's Training.
int solve1(vector<vector<int>>& points, int day, int last){ // M1 by recurssion
// last=0 -> TASK1, 1->TASK2, 2->TASK3, 3->TASK4.
    int a=0;
    if(day == 0){ // basecase.
        for(int i=0; i<3; i++){
            if(last != i)
                a = max(a, points[0][i]);
        }
        return a;
    }
    for(int i=0; i<3; i++){
        if(i != last){
            int x = points[day][i] + solve1(points, day-1, i);
            a = max(a, x);
        }
    }
    return a;
}

int solve2(vector<vector<int>>& points, vector<vector<int>>& dp, int day, int last){
    int a=0;
    if(day == 0){ // basecase.
        for(int i=0; i<3; i++){
            if(last != i)
                a = max(a, points[0][i]);
        }
        return a;
    }
    if(dp[day][last] != -1){
        return dp[day][last];
    }

    for(int i=0; i<3; i++){
        if(i != last){
            int x = points[day][i] + solve2(points, dp, day-1, i);
            a = max(a, x);
        }
    }
    dp[day][last] = a;
    return a;
}

    
int main(){
    int n;
    cin >> n; // (n >= 1)
    vector<vector<int>> points(n, vector<int>(3));
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> points[i][j]; // we consider all values to be +ve.
        }
    }
    vector<vector<int>>dp (n, vector<int>(4, -1));
    cout << solve1(points, n-1, 3) << endl;
    cout << solve2(points, dp, n-1, 3) << endl;

    return 0;
}