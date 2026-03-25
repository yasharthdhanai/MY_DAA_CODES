#include<iostream>
#include<vector>
using namespace std;

class Graph {
private:
    int vertices;
    vector<int> *adjacencyList;
    
    bool dfs(int current, int destination, vector<bool> &visited) {
        visited[current] = true;
        
        if (current == destination) {
            return true;
        }
        
        for (int neighbor : adjacencyList[current]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, destination, visited)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
public:
    Graph(int v) {
        vertices = v;
        adjacencyList = new vector<int>[v];
    }
    
    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(v);  // For undirected graph
    }
    
    bool pathExists(int source, int destination) {
        vector<bool> visited(vertices, false);
        return dfs(source, destination, visited);
    }
};

int main() {
    Graph g(5);
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    
    int source = 0, destination = 4;
    
    if (g.pathExists(source, destination)) {
        cout << "Path exists between " << source << " and " << destination << endl;
    } else {
        cout << "No path exists between " << source << " and " << destination << endl;
    }
    
    return 0;
}