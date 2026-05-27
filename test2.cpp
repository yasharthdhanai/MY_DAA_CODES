#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> AdjMat(m);
    for(int i=0; i<m; i++){
        int u, v, w; //st, dest, weight
        cin>> u >> v >> w;
        AdjMat[i] = {u, v, w};
    }


}