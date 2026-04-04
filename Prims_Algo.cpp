#include<bits/stdc++.h>
using namespace std;
    
int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>>AdjMat(V , vector<int>(V,INT_MAX));

    for(int i=0 ; i<E ;i++){
        int wt , u , v;
        cin >> wt >> u >> v;
        AdjMat[u][v] = wt;
        AdjMat[v][u] = wt;
    }

    vector<int> visited(V, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min heap
    int source = 0;
    pq.push({0, source}); // (wt , source). not parent here, parent is required for path printing.

    int cost = 0;

    //for fully connected graph.
    while(! pq.empty()){
        pair<int, int> val = pq.top();
        pq.pop();
        int wt = val.first;
        int node = val.second;
        if(visited[node])
            continue;
        visited[node] = 1;
        cost += wt;

        // cover all not visited nodes.

        for(int i=0 ; i<V ; i++){
            if(AdjMat[node][i] != INT_MAX && !visited[i]){
                pq.push({AdjMat[node][i], i});
            }
        }

    }
    cout << cost << endl;
    return 0;
}