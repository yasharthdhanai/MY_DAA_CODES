#include<bits/stdc++.h>
using namespace std;
    
//GOOD WAY. in recursion we dont use stack we use recursion as stack.
void dfs(vector<vector<int>>& Adj_List , vector<int>& visited, int st){
    for(int x : Adj_List[st]){
        if(!visited[x]){
            visited[x] = 1;
            cout << "->" << x;
            dfs(Adj_List, visited, x);
        }
    }
}
    
int main(){
    int V, E;
    cin >> V >> E; // POINTS and lines

    vector<vector<int>>Adj_List(V);

    for(int i=0; i<E ; i++){
        int v1, v2;
        cin >> v1 >> v2;
        Adj_List[v1].push_back(v2);
        Adj_List[v2].push_back(v1);
    }
    vector<int> visited(V,0);
    for(int i=0 ; i<V ; i++){  // work for both connected and disconnected graph.
        if(!visited[i]){
            visited[i] = 1;
            cout << i ;
            dfs(Adj_List, visited, i);
        }
    }
    return 0;
}