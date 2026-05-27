#include<bits/stdc++.h>
using namespace std;

// Min Heap :- priority_queue<int, vector<int>, greater<int>> minHeap;
// Max Heap :- priority_queue<int> maxHeap;

// Dijkstra Algo.

int main(){
    int V, E;
    cout << "Enter Vertices : ";
    cin >> V;
    cout << "Enter Edges : ";
    cin >> E;

    vector<pair<int, int>> AdjList[V];
    for(int i=0 ; i<E ; i++){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt ;
        AdjList[v1].push_back({v2, wt});
        AdjList[v2].push_back({v1, wt});
    }
    int st;
    cin >> st;

    priority_queue<pair<int,int>,  vector<pair<int,int>>, greater<pair<int,int>>> q; //min heap

    vector<int> distance(V, INT_MAX);
    distance[st] = 0;
    q.push({0, st});// 1st distance then node.

    while(! q.empty()){
        int a = q.top().first; //dis
        int b = q.top().second; //node
        q.pop();

        if(a > distance[b])
            continue;
        for(auto x : AdjList[b]){
            if(a+x.second < distance[b]){
                distance[b] = a+x.second;
                q.push({distance[b], x.first});
            }
        }
    }

    cout << "Shortest distance from node " << st << ":\n";
    for(int i=0 ; i<V ; i++)
        cout << "Node " << i << ": " << distance[i] << "\n";
        
    return 0;
}