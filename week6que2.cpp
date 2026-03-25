#include<bits/stdc++.h>
using namespace std;
    
bool bipartite(vector<vector<int>>& Adj_List, vector<int>& coloured, queue<int>& q){
    if(q.empty())
        return true;
    int y = q.front();
    q.pop();
    int a;
    if(coloured[y] == 1)
        a = 2;
    else a = 1;
    for(int x : Adj_List[y]){
        if(coloured[x] == 0){
            q.push(x);
            coloured[x] = a;
        }
        else if(coloured[x] != a)
            return false;
    }
    return bipartite(Adj_List, coloured, q);
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

    vector<int> coloured(V,0); // 1 blue, 2 red.
    //staring node 
    coloured[0] = 1; // node 0 is blue coloured.
    queue<int> q;
    q.push(0);
    if(bipartite(Adj_List, coloured, q))
        cout << "Yes Bipartite.\n";
    else
        cout << "Not Bipartite.\n";

    return 0;
}