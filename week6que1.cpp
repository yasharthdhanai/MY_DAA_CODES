#include<bits/stdc++.h>
using namespace std;

    // Finding path betweeen 2 vertices in undirected graph. (dfs) 
    bool dfs(vector<vector<int>>& Adj_List, vector<int>& Vis, int S, int D){
        if(S == D)
            return true;
        Vis[S] = 1;
        for(int i=0 ; i<Adj_List[S].size(); i++){
            if(! Vis[Adj_List[S][i]]){
                bool x = dfs(Adj_List, Vis, Adj_List[S][i], D);
                if(x)
                return true;
            }
        }
        return false;
    }
    
int main(){
    int V, E;
    cout << "Enter V : "; 
    cin >> V; // (points)
    cout << "Enter E : "; 
    cin >> E; // (lines)

    vector<vector<int>> Adj_List(V);
    vector<int> Visited(V, 0);
    
    for(int i=0 ; i<E ; i++){
        int v1 , v2;
        cout << "Enter v1 and v2 : ";
        cin >> v1 >> v2;
        Adj_List[v1].push_back(v2);
        // for undirected graph.
        Adj_List[v2].push_back(v1);
    }

    int sc, des; // source and dest vertices
    cout << "Enter S : "; 
    cin >> sc;
    cout << "Enter D : "; 
    cin >> des;

    if(dfs(Adj_List, Visited, sc, des))
        cout << "YES path exists! \n";
    else
        cout << "NO such path exists! \n";
    
    return 0;
}