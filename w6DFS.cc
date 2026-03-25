#include<iostream>
#include<vector>
using namespace std;
void gedichecker(int s, vector<int> adjList[], vector<int> & vis){
    vis[s] = 1;
    cout<< s << " -> ";
    for(int dost : adjList[s]){
        if(vis[dost] == 0){
            gedichecker(dost ,adjList, vis);
        }
    }
}
int main(){
    int V, E;
    cin>> V >>E;
    vector<int> adjList[V];
    for (int i = 0; i < E; i++){
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    for (int i = 0; i < V; i++){
        cout << i << " :- " ;
        for (int j = 0; j < adjList[i].size(); j++){
            cout << adjList[i][j] << " ";
        }
        cout << "\n";    
    }
// --------------------------------------------------------------- //

    vector<int>visited(V,0); //sari vertices me 0 pada hai

    int start, end;
    cin >> start >> end;
    gedichecker(start, adjList, visited);
    if(visited[end] == 1){
        cout << "Yes you can reach to your Friend's of friend.\n";
    }
    else{
        cout << "No you can't reach to your destination.\n";
    }
    for(int  i = 0; i<V ; i++){
        cout << visited[i] << " ";
    }
    cout << "\n";
    return 0;
}
