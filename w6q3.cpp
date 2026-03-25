#include <iostream>
#include <vector>

using namespace std;

bool iscycle(vector<int>& visited, int v, vector<vector<int>>& AdjList, vector<int>& path) {
    visited[v] = 1;

    for(auto next : AdjList[v]) {
        if(visited[next] == 0) {
            path[next] = v;
            if(iscycle(visited, next, AdjList, path)) {
                return true;
            }
        }
        else if(visited[next] == 1) { 
            return true;
        }
    }

    visited[v] = 2;
    return false;
}

int main() {
    int V, E;
    cin >> V >> E; 

    vector<vector<int>> AdjList(V);
    vector<int> visited(V, 0);
    int v1, v2;

    for(int i = 0; i < E; i++) {
        cin >> v1 >> v2;
        AdjList[v1].push_back(v2); 
    }

    for(int i = 0; i < V; i++) {
        cout << i << " :- ";
        for (int j = 0; j < AdjList[i].size(); j++) {
            cout << AdjList[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> path(V, 0);
    bool hasCycle = false;

    for(int i = 0; i < V; i++) {
        if(visited[i] == 0) {
            if(iscycle(visited, i, AdjList, path)) {
                hasCycle = true;
                break;
            }
        }
    }

    if(hasCycle) {
        cout << "Cycle is Present\n";
    } else {
        cout << "Cycle is not Present\n";
    }

    return 0;
}