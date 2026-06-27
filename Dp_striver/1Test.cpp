#include<bits/stdc++.h>
using namespace std;
    
int main(){
    srand(time(0));

    int n = 50;
    vector<vector<int>> grid(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            grid[i][j] = rand() % 3 - 1; // -1, 0, 1
        }
    }

    if(grid[0][0] == -1) grid[0][0] = 0;
    if(grid[n-1][n-1] == -1) grid[n-1][n-1] = 0;

    cout << "[";

    for(int i = 0; i < n; i++) {
        cout << "[";

        for(int j = 0; j < n; j++) {
            cout << grid[i][j];
            if(j != n - 1) cout << ",";
        }

        cout << "]";
        if(i != n - 1) cout << ",";
    }

    cout << "]" << endl;

    return 0;
}