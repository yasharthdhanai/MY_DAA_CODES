#include<iostream>
 #include<vector>
  using namespace std; 
 
bool dfs(int node, vector<vector<int>>& adjMatrix, vector<int>& vis, vector<int>& pathVis, int v) {     
    vis[node] = 1;     
    pathVis[node] = 1; 
 
    for(int i = 0; i < v; i++) {         
        if(adjMatrix[node][i] == 1) { 
            if(vis[i] == 0) {                 
                if(dfs(i, adjMatrix, vis, pathVis, v)) {                     
                    return true; 
                } 
            } 
            else if(pathVis[i] == 1) {                 
                return true; 
            } 
        } 
    } 
 
    pathVis[node] = 0; // backtrack     return false; 
} 
 
bool isCycle(vector<vector<int>>& adjMatrix, int v) {     vector<int> vis(v, 0);     vector<int> pathVis(v, 0); 
 
    for(int i = 0; i < v; i++) {         if(vis[i] == 0) {             if(dfs(i, adjMatrix, vis, pathVis, v)) {                 return true; 
            } 
        } 
    } 
    return false; 
} 
 
int main() { 
    int v;     cin >> v; 
 
    vector<vector<int>> adjMatrix(v, vector<int>(v)); 
 
    for(int i = 0; i < v; i++) {         for(int j = 0; j < v; j++) { 
            cin >> adjMatrix[i][j]; 
        } 
    } 
 
    if(isCycle(adjMatrix, v)) {         cout << "Yes Cycle Exists" << endl; 
    } else { 
        cout << "No Cycle Exists" << endl; 
    } 
 
    return 0; 
} 
