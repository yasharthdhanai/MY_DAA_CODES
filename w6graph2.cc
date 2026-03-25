#include<iostream>
#include<vector>

using namespace std;

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
    return 0;
}
