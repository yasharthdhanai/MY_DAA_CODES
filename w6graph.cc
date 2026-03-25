#include<iostream>
using namespace std;

void addEdge(int** arr, int i, int j){
    arr[i][j] = 1;
    arr[j][i] = 1;
}

int main(){
    int V = 6;
    int** matrix = new int*[V];
    for(int i = 0; i<V ; i++){
        matrix[i] = new int[V];
        for (int j = 0; j < V; j++){
            matrix[i][j] = 0;
        }
    }
    addEdge(matrix, 0, 1);
    addEdge(matrix, 0, 3);
    addEdge(matrix, 1, 5);
    addEdge(matrix, 3, 5);
    addEdge(matrix, 2, 5);
    addEdge(matrix, 4, 2);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
return 0;
}