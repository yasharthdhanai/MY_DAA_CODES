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

int solve2(vector<vector<int>>& points, vector<vector<int>>& dp, int day, int last){ // M2 by memoization
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

int solve3 (vector<vector<int>>& points){ // M3 by Tabulation.
    int n = points.size();
    vector<vector<int>>dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day=1; day<n; day++){
        for(int last=0; last<4; last++){
            dp[day][last] = 0;
            for(int i=0; i<3; i++){                        //  <--|    Same as M2
                if(i != last){                             //     |    we are just
                    int x = points[day][i] + dp[day-1][i]; //     |--- filling the
                    dp[day][last] = max(dp[day][last], x); //     |    dp table in 
                }                                          //     |    bottom up manner.
            }                                              //  <--|
        }
    }
    return dp[n-1][3];
}

int solve4 (vector<vector<int>>& points){   // M4 by Space Optimization.
    int n = points.size();
    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day=1; day<n; day++){
        vector<int> curr(4, 0);
        for(int last=0; last<4; last++){
            curr[last] = 0;
            for(int i=0; i<3; i++){                        //  <--|    Same as M2
                if(i != last){                             //     |    we are just
                    int x = points[day][i] + prev[i];      //     |--- filling the
                    curr[last] = max(curr[last], x);       //     |    dp table in 
                }                                          //     |    bottom up manner.
            }                                              //  <--|
        }
        prev = curr;
    }
    return prev[3];
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
    cout << solve3(points) << endl;
    cout << solve4(points) << endl;
    return 0;
}