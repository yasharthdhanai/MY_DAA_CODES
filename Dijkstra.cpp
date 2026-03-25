#include<bits/stdc++.h>
using namespace std;
    
int main(){
    int V, E;
    cin >> V >> E;

    vector<pair<int, int>> AdjList[V];
    for(int i=0 ; i<E ; i++){
        int u, v,  wt;
        cin >>u >>v >> wt;
        AdjList[u].push_back({v, wt});
        AdjList[v].push_back({u, wt}); // 1st is node 2nd is weight.
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    int st ;
    cin >> st;
    vector<int>distance(V, INT_MAX);
    distance[st] = 0;

    minHeap.push({0, st}) ; // 1st is distance 2nd is node.

    while(! minHeap.empty()){
        int a = minHeap.top().first; // distance
        int b = minHeap.top().second; // node
        distance[a] = b;

        minHeap.pop();

        for(auto x : AdjList[minHeap.top().second]){
            int node = x.first;
            int weight = x.second;
            minHeap.push({weight, node}) ;
        }
    }

    cout << "Shortest distance from node " << st << ":\n";
    for(int i=0 ; i<V ; i++)
        cout << "Node " << i << ": " << distance[i] << "\n";

    return 0;
}