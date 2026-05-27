#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>>& AdjList, vector<int>& visited){
    visited[node] = 1;
    for(auto next : AdjList[node]){
        if(visited[next] == 0){
            DFS(next, AdjList, visited);
        }
    }
}

int main(){
    int V, E;
    cout << "Enter number of vertices : ";
    cin >> V;
    cout << "Enter number of edges : ";
    cin >> E;

    vector<vector<int>> AdjList(V);
    cout << "Enter directed edges : \n";
    for(int i=0 ; i<E ; i++){
        int u, v;
        cin >> u >> v;
        AdjList[u].push_back(v);
    }

    vector<int> visited(V, 0);

    int motherVertex = -1;

    // Find possible mother vertex
    for(int i=0 ; i<V ; i++){
        if(visited[i] == 0){
            DFS(i, AdjList, visited);
            motherVertex = i;
        }
    }

    // Verify mother vertex
    fill(visited.begin(),  visited.end(),  0);

    DFS(motherVertex,  AdjList, visited);

    bool possible = true;

    for(int i=0 ; i<V ; i++){
        if(visited[i] == 0){
            possible = false;
            break;
        }
    }

    if(possible){
        cout << "\nMother Vertex = " << motherVertex;
    }

    else{
        cout << "\nMother Vertex does not exist";
    }

    return 0;
}