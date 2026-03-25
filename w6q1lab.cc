#include<iostream>
#include<vector>
using namespace std;

bool isPath(int cur, int dest, int n, vector<vector<int>> &adj, vector<bool> &vis) {
    if (cur == dest)
        return true;
    vis[cur] = true;
    for (int i = 0; i < n; i++) {
        if (adj[cur][i] == 1 && !vis[i]) {
            if (isPath(i, dest, n, adj, vis)) {
                return true; 
            }
        }
    }
    return false;
}
int main(){
    int n; //no. of nodes
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for(int i=0; i<n ; i++){
        for(int j=0; j<n ; j++){
            cin >> adj[i][j];
        }
    }
    int u, v;
    cin >> u >> v;//u current , v dest
    vector<bool> vis(n, false);
    if(isPath(u-1, v-1, n, adj, vis)){
        cout<<"Yes Path exists.\n";
    }
    else{
        cout<<"No such Path exists.\n";
    }
    return 0;
}