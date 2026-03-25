#include<bits/stdc++.h>
using namespace std;
    
bool cycle(vector<vector<int>>& Adj_List , vector<int>& visited , stack<int>& stk){
    if(stk.empty())
        return false;
    int x = stk.top();
    stk.pop();
    for(int y : Adj_List[x]){
        if(visited[y] == 0){
            visited[y] = 1;
            stk.push(y);
        }
        else
            return true;
    }
    return cycle(Adj_List , visited , stk);
}
    
int main(){
    int V, E;
    cin >> V >> E; // POINTS and lines

    vector<vector<int>>Adj_List(V);
    for(int i=0; i<E ; i++){
        int v1, v2;
        cin >> v1 >> v2;
        Adj_List[v1].push_back(v2);
    }

    for(int i=0 ; i<V ; i++){
        vector<int>visited (V,0);
        stack<int> stk;
        stk.push(i);
        bool x = cycle(Adj_List , visited , stk);
        if(x){
            cout << "Cycle Present.\n";
            return 0;
        }
    }
    cout << "Cycle not Present.\n";

    return 0;
}