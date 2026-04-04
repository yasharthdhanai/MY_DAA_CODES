#include<bits/stdc++.h>
using namespace std;
    
bool IsInSameComponent(int u, int v, vector<vector<int>>& NewGraphAdj, vector<int>& visited){
    if(u == v)
        return true;
    visited[u] = 1;
    for(auto x : NewGraphAdj[u]){
        if(!visited[x]){
            if(IsInSameComponent(x, v, NewGraphAdj, visited))
                return true;
        }
    }
    return false;
}
void AddInCom(int u, int v, vector<vector<int>>& NewGraphAdj){
    NewGraphAdj[u].push_back(v);
    NewGraphAdj[v].push_back(u);

}

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>>AdjList;
    // We have to create a Minimum spanning tree. So we have to store[i][0] = weight.
    for(int i=0 ; i<E ;i++){
        int wt , u , v;
        cin >> wt >> u >> v;
        AdjList.push_back({wt, u, v});
    }
    sort(AdjList.begin(), AdjList.end());

    vector<vector<int>> NewGraphAdj(V+1);
    
    int cost = 0;
    for(auto val : AdjList){
        int wt = val[0];
        int u = val[1];
        int v = val[2];
        vector<int> visited(V+1, 0);
        if( ! IsInSameComponent(u , v, NewGraphAdj, visited)){
            cost += wt;
            AddInCom(u, v, NewGraphAdj);
        }
    }
    cout << cost;
    return 0;
}