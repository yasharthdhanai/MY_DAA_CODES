#include<bits/stdc++.h>
using namespace std;
    
// Dijkstra's Algorithm Implementation on undirected graph using adjacency list and priority queue (min-heap).
// In Dijkstra's algorithm, negitive weight edges give incorrect answer.
// So we can subtract a smallest number (like we do in counting sort) to all the weights to make them positive and then apply Dijkstra's algorithm.
// But this is not a good approach as it can lead to overflow and also it can give incorrect answer if the graph has negative weight cycles.
// So it is better to use Bellman-Ford algorithm for graphs with negative weight edges.


// struct PAIR{
//     int first;
//     int second;
// }
    
int main(){
    int V, E;
    cin >> V >> E;

    // vector<vector<int>>Adj_Matrix(V, vector<int>(V,0));
    // for(int i=0 ;i<V ;i++){
    //     for(int j=0 ; j<V ; j++){
    //         int wt;
    //         cin >> wt;
    //         Adj_Matrix[i][j] = wt;
    //     }
    // }

    vector<pair<int, int>> Adj_List[V]; // 1st is node 2nd is weight
    for(int i=0 ;i<E ;i++){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        Adj_List[v1].push_back({v2, wt});
        Adj_List[v2].push_back({v1, wt});
    }

    int StNode = 0;
    vector<int>distance(V, INT_MAX);
    distance[StNode] = 0;

    // priority_queue<pair<int , int>> pq; // max_heap.
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // min_heap.

    pq.push({0, StNode}); // 1st is distance 2nd is destination;

    while(! pq.empty()){
        int vertex = pq.top().second ;
        int weight = pq.top().first ;
        pq.pop();

        if(weight > distance[vertex])
            continue;
        
        for(auto x : Adj_List[vertex] ){
            int AdjVertex = x.first;
            int AdjWt = x.second;

            int d = weight + AdjWt;
            if(d < distance[AdjVertex]){
                distance[AdjVertex] = d;
                pq.push({d, AdjVertex});
            }
        }
    }

    cout << "Shortest distances from node " << StNode << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : " << distance[i] << "\n";
    }

    return 0;
}