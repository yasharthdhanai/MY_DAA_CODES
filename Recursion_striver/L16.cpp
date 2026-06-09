#include<bits/stdc++.h>
using namespace std;
    
// N-Queens
bool isvalid(int x, int y, vector<string> & temp){                    // --> O(n). (overall T.C.)
    int n = temp.size();
    // We need not to check for columns as we are placing Queens column wise.
    for(int i=0; i<n; i++){ // on same row
        if(temp[x][i] == 'Q'){                                         // --> O(n).  
            return false;
        }
    }
    for(int i=0; i<n; i++){ //on diagonals
        if((x-i) >=0 && (y-i) >= 0 && temp[x-i][y-i] == 'Q'){
            return false;
        }                                                               // --> O(n).
        if((x+i) < n && (y-i) >= 0 && temp[x+i][y-i] == 'Q'){
            return false;
        }
        // We also need not to check for y+1 as all those colums are empty now.
    }
    return true;
}

// We can reduce time complexity of isvalid function from O(n) to O(1) with help of hashing.
// As we need to check only upper left diagonal, lower left diagonal and left row.
// In solve2 function we do the following changes. 

void solve(vector<vector<string> > & result, vector<string> & temp, int n, int col){
    if(col == n){
        result.push_back(temp);
        return;
    }
    for(int i=0; i<n; i++){
        if(isvalid(i, col, temp)){
            temp[i][col] = 'Q';
            solve(result, temp, n, col+1);
            temp[i][col] = '.';
        }
    }
}


void solve2(vector<vector<string> > & result, vector<string> & temp, vector<int>& leftR, vector<int>& UpperD, vector<int>& LowerD, int n, int col){
    if(col == n){
        result.push_back(temp);
        return;
    }
    for(int i=0; i<n; i++){
        if(leftR[i] == 0 && UpperD[n-1+col-i] == 0 && LowerD[i+col] == 0){
            temp[i][col] = 'Q';
            leftR[i] = 1;
            UpperD[n-1+col-i] = 1;
            LowerD[i+col] = 1;
            solve2(result, temp, leftR, UpperD, LowerD, n, col+1);
            temp[i][col] = '.';
            leftR[i] = 0;
            UpperD[n-1+col-i] = 0;
            LowerD[i+col] = 0;
        }
    }
    return;
}
vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > result;
    vector<string> temp(n, string(n, '.'));

    vector<int> leftR(n, 0);
    vector<int> UpperD(2*n-1, 0);
    vector<int> LowerD(2*n-1, 0);
    solve(result, temp, n, 0); // 0 is column.
    solve2(result, temp, leftR, UpperD, LowerD, n, 0);
    return result;
}

int main(){
    
    return 0;
}