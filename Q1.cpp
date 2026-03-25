#include<bits/stdc++.h>
using namespace std;
    
int bfs(vector<vector<int>>& Adj_List, vector<int>& visited, queue<int>& infected){
    int min = 0;
    while(!infected.empty()){
        int size = infected.size();
        while(size--){
            int x = infected.front();
            infected.pop();
            for(int z : Adj_List[x]){
                if(visited[z] == 0){
                    infected.push(z);
                    visited[z] = 1;
                }
            }
        }
        if(!infected.empty())
            min++;
    }

    for(int i : visited){
        if(!i)
            return -1;
    }
    return min;
}
    
int main(){
    int V, E;
    cin >> V >> E; // POINTS and lines

    vector<vector<int>>Adj_List(V+1);
    for(int i=0; i<E ; i++){
        int v1, v2;
        cin >> v1 >> v2;
        Adj_List[v1].push_back(v2);
    }

    vector<int> visited(V+1,0);
    queue<int> infected;
    int infect1;
    cin >> infect1;
    infected.push(infect1);
    visited[infect1] = 1;
    int min = bfs(Adj_List, visited, infected);
    cout << min;
    return 0;
}