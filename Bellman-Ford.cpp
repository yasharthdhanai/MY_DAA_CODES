#include<bits/stdc++.h>
using namespace std;
       
int main(){
    int V, E;

    cin >> V >> E;
        
    vector<vector<pair<int, int>>> adj(V);
    vector<int> dist(V, INT_MAX);
    
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    int src;
    cin >> src;
    dist[src] = 0;
    
    for(int i = 0; i < V - 1; i++){
        for(int u = 0; u < V; u++){
            if(dist[u] != INT_MAX){
                for(auto &edge : adj[u]){
                    int v = edge.first;
                    int w = edge.second;
                    if(dist[u] + w < dist[v]){
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < V; i++){
        cout << "Distance to " << i << ": " << dist[i] << "\n";
    }
    return 0;
}