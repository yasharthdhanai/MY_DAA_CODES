#include<bits/stdc++.h>
using namespace std;

int main(){
    // Adj. List
    int V, E;
    cout << "Enter Vertices : ";
    cin >> V;
    cout << "Enter Edges : ";
    cin >> E;

    vector<vector<int>> AdjList(V);
    int v1, v2;
    for(int i=0 ; i<E ; i++){
        cin >> v1 >> v2;
        AdjList[v1].push_back(v2);
        AdjList[v2].push_back(v1);
    }
    
    // Adj. Matrix
    int v; // vertices(nodes)
    cin >> v; 
    vector<vector<int>> AdjMat(v, vector<int>(v)); // matrix of v*v is formed.
    for(int i=0 ; i<v ; i++){
        for(int j=0 ; j<v ; j++){
            cin >> AdjMat[i][j]; // we can input weight(weighted graph).
            // in non-weighted graph 1 if there is a path, else 0.
        }
    }
}