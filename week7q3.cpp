#include<bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cout << "Enter Vertices : ";
    cin >> V;
    cout << "Enter Edges : ";
    cin >> E;

    vector<vector<int>> edges;
    for(int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    int source, destination, k;
    cout << "Enter Source : ";
    cin >> source;
    cout << "Enter Destination : ";
    cin >> destination;
    cout << "Enter K : ";
    cin >> k;

    const int INF = 1e9;

    // dp[i][j] = shortest distance to reach j using exactly i edges
    vector<vector<int>> dp(k+1, vector<int>(V, INF));

    dp[0][source] = 0;

    // Relax edges exactly k times
    for(int i = 1; i <= k; i++) {
        for(auto x : edges) {
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            if(dp[i-1][u] != INF) {
                dp[i][v] = min(dp[i][v], dp[i-1][u] + wt);
            }
        }
    }

    if(dp[k][destination] == INF)
        cout << "No path exists\n";
    else
        cout << "Shortest Path Weight = " << dp[k][destination];

    return 0;
}