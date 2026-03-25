#include<bits/stdc++.h>
using namespace std;
    
//GOOD WAY.
void BFS (vector<vector<int>>& Adj_List,vector<int>& visited, queue<int>& q, int st){
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(st == 1){
            cout << x;
            st = 0;
        }
        else
            cout <<"->" << x;
        for(int z : Adj_List[x]){
            if(visited[z] == 0){
                q.push(z);
                visited[z] = 1;
            }
        }
    }
    return;
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

    cout << "Diffrent Paths :- \n";
    vector<int> visited(V, 0);
    for(int i=0 ; i<V ; i++){
        if(visited[i] == 0){
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            BFS(Adj_List, visited, q, 1);
            cout << endl;
        }
    }
    return 0;
}

// 8 6
// 0 1  disconnected graph
// 0 6
// 1 2
// 3 4
// 4 5
// 5 7