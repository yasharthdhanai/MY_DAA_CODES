#include<iostream> 
#include<vector>
#include<queue>
using namespace std; 
 
bool isBipartite(vector<vector<int>>& adjMatrix, int v) {
    vector<int> color(v, -1); // -1 = not colored 
 
    for(int start = 0; start < v; start++) {
        if(color[start] == -1) {
            queue<int> q;             
            q.push(start);             
            color[start] = 0;  
            while(!q.empty()) {  
                int node = q.front();
                q.pop(); 
 
                for(int i = 0; i < v; i++) {  
                    if(adjMatrix[node][i] == 1) {                         // If not colored
                        if(color[i] == -1) {
                            color[i] = 1 - color[node];
                            q.push(i); 
                        } 
                        // If same color → not bipartite
                        else if(color[i] == color[node]) {  
                            return false; 
                        } 
                    } 
                } 
            } 
        } 
    }
    return true; 
} 
 
int main() { 
    int v;     
    cin >> v; 
 
    vector<vector<int>> adjMatrix(v, vector<int>(v)); 
 
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {             
            cin >> adjMatrix[i][j]; 
        } 
    } 
 
    if(isBipartite(adjMatrix, v)) {         
        cout << "Yes Bipartite" << endl; 
    } 
    else {         
        cout << "Not Bipartite" << endl; 
    } 
 
    return 0; 
} 
