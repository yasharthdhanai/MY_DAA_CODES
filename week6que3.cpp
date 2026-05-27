#include<bits/stdc++.h>
using namespace std;

bool cycle(vector<vector<int>>& AdjList, vector<int>& visited, int st, int parent){ // DFS
    int ans = false;
    visited[st] = 1;

    for(auto x : AdjList[st]){
        if(visited[x] == 0){
            if(cycle(AdjList, visited, x, st)){
                return true;
            }
        }
        // If visited and not parent
        else if(x != parent){
            return true;
        }
    }
    return ans;
}
int main(){
    int V, E;
    cout << "Enter Vertices : ";
    cin >> V;
    cout << "Enter Edges : ";
    cin >> E;

    vector<vector<int>> AdjList(V);
    int v1, v2;
    for(int i=0 ; i<E ; i++){
        cin >> v1 >> v2;
        AdjList[v1].push_back(v2);
        AdjList[v2].push_back(v1);
    }

    vector<int> vis(V, 0);

    bool ans = false;
    for(int i=0 ; i<V ; i++){
        vector<int> visited(V, 0);
        if(cycle(AdjList, visited, i, -1)){
            ans = true;
            break;
        }
    }

    if(ans){
        cout << "Yes Cycle Exists."; 
    }
    else{
        cout << "No Cycle doesn't Exists."; 
    }

    return 0;
}