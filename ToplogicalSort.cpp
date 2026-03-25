#include<bits/stdc++.h>
using namespace std;
    
// Topological Sort. (using stack)
// 1.Graph should be directed.
// 2. Graph should be acyclic.
void TopogicalSort(int node, vector<int> Adj_List[], stack<int>& stk, vector<int>& visited){
    visited[node] = 1;
    for(int x : Adj_List[node]){
        if(!visited[x]){
            TopogicalSort(x, Adj_List, stk, visited);
        }
    }
    stk.push(node);
}
int main(){
    int V , E;
    cin >>V >> E;

    vector<int>Adj_List[V];
    for(int i=0; i<E; i++){
        int u, v;
        cin >> u >> v;
        Adj_List[u].push_back(v);
    }

    stack<int> stk;
    vector<int> visited(V, 0);

    for (int i = 0; i < V; i++) {
        int node = i;
        if (!visited[i]) {
            TopogicalSort(node, Adj_List, stk, visited);
        }
    }

    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }

    return 0;
}