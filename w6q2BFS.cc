#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

bool isBipartite(vector<int>& VisArr, queue<int>& level, vector<int> AdjList[], vector<int>& Colour ){
    Colour[level.front()] = 1;
    while(!level.empty()){
        int current = level.front();
        for(auto next : AdjList[current]){
            level.push(next);
            if(Colour[next] == Colour[current]){
                return false;
            }
            else if(Colour[next] == -1){
                Colour[next] = !Colour[current];
            }
        }
    }
    return true;
}

int main(){
    int V , E;
    cin >> V >> E;

    // Now we have to make Adj list.
    vector<int> AdjList[V]; // array of vector
    int v1, v2;
    for(int i=0; i<E ;i++){
        cin >> v1 >> v2;
        AdjList[v1].push_back(v2);
        AdjList[v2].push_back(v1);
    }
    for(int i=0; i<E ; i++){
        cout << i <<" :- " ;
        for (int j = 0; j < AdjList[i].size(); j++){
            cout << AdjList[i][j] << " ";
        }
    }

    vector<int> VisArr(V, -1);
    vector<int> Colour;
    queue<int> level;

    int st=0;
    level.push(0);

    if(isBipartite(VisArr, level, AdjList, Colour )){
        cout << "Bipartite.\n";
    }
    else
        cout << "Not Bipartite.\n";
    return 0 ;
}

// void gedichecker(int start, vector<int> adjList[], vector<int> & vis, queue<int>& pehlemeredost){
//     vis[start] = 1;
//     int a = pehlemeredost.front();
//     for(int dost : adjList[start]){
//         if(vis[dost] == 0)
//             pehlemeredost.push(dost);
//     }
//     gedichecker(a, adjList, vis, pehlemeredost);

// }
// int main(){
//     int V, E;
//     cin>> V >>E;
//     vector<int> adjList[V];
//     queue<int>pehlemeredost;
    
//     for (int i = 0; i < E; i++){
//         int x, y;
//         cin >> x >> y;
//         adjList[x].push_back(y);
//         adjList[y].push_back(x);
//     }

//     // this is for displaying adj list.
//     for (int i = 0; i < V; i++){
//         cout << i << " :- " ;
//         for (int j = 0; j < adjList[i].size(); j++){
//             cout << adjList[i][j] << " ";
//         }
//         cout << "\n";    
//     }

// // --------------------------------------------------------------- //

//     vector<int>visited(V,0); //sari vertices me 0 pada hai

//     int start, end;
//     cin >> start >> end;
    
//     pehlemeredost.push(start);

//     gedichecker(start, adjList, visited, pehlemeredost);

//     if(visited[end] == 1){
//         cout << "Yes you can reach to your Friend's of friend.\n";
//     }
//     else{
//         cout << "No you can't reach to your destination.\n";
//     }
//     for(int  i = 0; i<V ; i++){
//         cout << visited[i] << " ";
//     }
//     cout << "\n";
//     return 0;
// }
