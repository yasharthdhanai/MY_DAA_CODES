#include<bits/stdc++.h>
using namespace std;

// Bellman-Ford Algorithm

int main() {
    int V, E;

    cout << "Enter Vertices : ";
    cin >> V;

    cout << "Enter Edges : ";
    cin >> E;

    vector<vector<int>> edges;

    // Input edges
    for(int i = 0; i < E; i++) {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;

        // {source, destination, weight}
        edges.push_back({v1, v2, wt});

        // Remove this line if graph is directed
        edges.push_back({v2, v1, wt});
    }

    int st;
    cin >> st;

    vector<int> distance(V, INT_MAX);
    distance[st] = 0;

    // Relax all edges V-1 times
    for(int i = 0; i < V - 1; i++) {

        for(auto x : edges) {

            int u = x[0];
            int v = x[1];
            int wt = x[2];

            if(distance[u] != INT_MAX &&
               distance[u] + wt < distance[v]) {

                distance[v] = distance[u] + wt;
            }
        }
    }

    // Check for negative weight cycle
    bool negativeCycle = false;

    for(auto x : edges) {

        int u = x[0];
        int v = x[1];
        int wt = x[2];

        if(distance[u] != INT_MAX &&
           distance[u] + wt < distance[v]) {

            negativeCycle = true;
            break;
        }
    }

    if(negativeCycle) {
        cout << "Negative Weight Cycle Found\n";
    }
    else {
        cout << "Shortest distance from node " << st << ":\n";

        for(int i = 0; i < V; i++) {
            cout << "Node " << i << ": " << distance[i] << "\n";
        }
    }

    return 0;
}