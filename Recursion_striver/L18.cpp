#include<bits/stdc++.h>
using namespace std;

// M-coloring Problem (NP-Complete problem.)
// Logic same as N-Queen and Sudoko solver.
// Put colour and check if it can give us answer or not.

bool isSafe(bool graph[101][101], vector<int>& color, int N, int i, int node){
    // i is the color of node.
    for(int k=0; k<N; k++){
        if(k != node && graph[node][k] == 1 && color[k] == i)
            return false;
    }
    return true;
}
bool solve(bool graph[101][101], vector<int>&color, int N, int M,  int node){
    if(node == N){
        return true;
    }
    for(int i=1; i<=M; i++){
        if(isSafe(graph, color, N, i, node)){
            color[node] = i;
            if(solve(graph, color, N, M, node+1))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphcoloring( bool graph[101][101], int N, int M){
    // M is number of colors used (at max).
    // N is number of vertices graph is stored.
    vector<int>color(N,0);
    if(solve(graph, color, N, M, 0))
        return true;
    return false;
}
    
int main(){
    
    return 0;
}