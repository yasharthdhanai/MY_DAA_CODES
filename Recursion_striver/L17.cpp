#include<bits/stdc++.h>
using namespace std;

// Sudoko solver (Leetcode Q37).
// Simple logic as N-Queens.
// We can reduce time complexity of isvalid funtion from O(27) to O(1), as we do in N-Queens. 

// We make them global variable.
bool row[9][10] = {false}; // row[i][num] i=9 for 9*9 sudoko, num can be from 1-9 so num = 10.
bool col[9][10] = {false}; //  ,, (initial value is false).
bool box[9][10] = {false}; // For box[i][num], i = (row/3)*3 + (col/3) and 10.....

bool isvalid(vector<vector<char>>& board, int i, int j, int a){
    for(int x=0; x<9; x++){
        if(board[x][j] == a+'0' || board[i][x] == a+'0'){
            return false;
        }
    }
    int i_st = (i/3)*3;
    int j_st = (j/3)*3;
    for(int x=i_st; x<i_st+3; x++){
        for(int y=j_st; y<j_st+3; y++){
            if(board[x][y] == a+'0')
                return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>>& board){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j] == '.'){
                for(int x=1; x<=9; x++){
                    if(isvalid(board, i, j, x)){
                        board[i][j] = x + '0';
                        if(solve(board)){
                            return true;
                        }
                        else{
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isvalid2(vector<vector<char>>& board, int i, int j, int a){
    if(row[i][a] == false && col[j][a] == false && box[(i/3)*3 + j/3][a] == false){
        return true;
    }
    return false;
}

// Solve2 function has lower TC. O(1) for isvalid.
bool solve2(vector<vector<char>>& board, int I){
    for(int i=I; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j] == '.'){
                for(int x=1; x<=9; x++){
                    if(isvalid2(board, i, j, x)){ // we can remove is valid function and directly put conditions here.
                        board[i][j] = x + '0';
                        row[i][x] = true;
                        col[j][x] = true;
                        box[(i/3)*3 + j/3][x] = true;

                        if(solve2(board, i)){
                            return true;
                        }
                        else{
                            board[i][j] = '.';
                            row[i][x] = false;
                            col[j][x] = false;
                            box[(i/3)*3 + j/3][x] = false;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j] != '.'){
                int num = board[i][j] - '0';
                int b = (i/3)*3 + (j/3);

                row[i][num] = true;
                col[j][num] = true;
                box[b][num] = true;
            }
        }
    }
    solve2(board, 0); // i=0 at start
}
    
int main(){
    
    return 0;
}