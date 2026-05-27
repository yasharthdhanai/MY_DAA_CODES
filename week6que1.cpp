#include<bits/stdc++.h>
using namespace std;

//Time Complexity : O(V+E) 
bool ispathexists(vector<vector<int>>& AdjList,vector<bool>& visited, int st, int end){
    if(visited[st]){
        return false;
    }
    else{
        visited[st] = true;
    }
    bool ans = false;
    if(st == end){
        return true;
    }
    for(auto x : AdjList[st]){
        if(ispathexists(AdjList, visited, x, end))
            ans = true;
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

    int st, end;
    cin >> st;
    cin >> end;

    vector<bool> visited(V, 0);

    if(ispathexists(AdjList, visited, st, end)){
        cout<< "Yes Path Exists.";
    }
    else{
        cout<< "No Path didn't Exists.";
    }
    return 0;
}