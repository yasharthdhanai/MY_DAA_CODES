#include<bits/stdc++.h>
using namespace std;
    
// stack is used in iteration.
void dfs(vector<vector<int>>& Adj_List , vector<int>& visited, stack<int>& stk ,int m){
    while(!stk.empty()){
        int x = stk.top();
        stk.pop();
        if(m){
            cout << x;
            m = 0;
        }
        else
            cout << "->" << x;
        for(int z : Adj_List[x]){
            if(!visited[z]){
                stk.push(z);
                visited[z] = 1;
            }
        }
    }
}

int main(){
    int V, E;
    cin >> V >> E;  // POINTS and lines

    vector<vector<int>>Adj_List(V);
    for(int i=0; i<E ; i++){
        int v1, v2;
        cin >> v1 >> v2;
        Adj_List[v1].push_back(v2);
        Adj_List[v2].push_back(v1);  // Undirected Graph.
    }

    vector<int> visited(V,0);
    for(int i=0 ; i<V ; i++){  // work for both connected and disconnected graph.
        if(!visited[i]){
            stack<int> stk;
            stk.push(i);
            visited[i] = 1;
            dfs(Adj_List, visited, stk, 1);
            cout << endl;
        }
    }
    return 0;
}