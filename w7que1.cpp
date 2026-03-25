#include<bits/stdc++.h>
using namespace std;
    
int main() {
    int n, m;
    cin >> n >> m;
        
    vector<vector<pair<int, int>>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    int source;
    cin >> source;
    
    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[source] = 0;
    pq.push({0, source});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (i == source) continue;
        
        cout << "Node " << i << ": Distance = " << dist[i] << ", Path: ";
        
        vector<int> path;
        int curr = i;
        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        
        reverse(path.begin(), path.end());
        for (int j = 0; j < path.size(); j++) {
            cout << path[j];
            if (j < path.size() - 1) cout << " -> ";
        }
        cout << "\n";
    }
    return 0;
}
    