#include<bits/stdc++.h>
using namespace std;

bool bipartite(vector<vector<int>>& AdjList, vector<int>& colour, queue<int>& q){
    if(q.empty()){
        return true;
    }

    int a = q.front();
    q.pop();

    int c = 0;
    if(colour[a] == 1)
        c = 2;
    else
        c = 1;

    for(auto x : AdjList[a]){
        if(colour[x] != 0 && colour[x] != c){
            return false;
        }
        if(colour[x] == 0){
            colour[x] = c;
            q.push(x);
        }
    }
    return bipartite(AdjList, colour, q); 
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

    vector<int> colour(V, 0); // 0 for no colour 1 for red 2 for green.
    // we are taking connected graph.

    queue<int> q;
    colour[0] = 1;
    q.push(0);
    if(bipartite(AdjList, colour, q)){
        cout << "Graph is bipartite."; 
    }
    else{
        cout << "Graph is not bipartite."; 
    }

    return 0;
}