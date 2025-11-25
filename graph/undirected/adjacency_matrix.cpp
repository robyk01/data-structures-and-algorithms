#include <iostream>
using namespace std;
#define NMAX 101

int G[NMAX][NMAX], n;

/*
    Adds and edge between u and v vertices
*/
void addEdge(int G[][NMAX], int u, int v){
    if (u < n && v < n){
        G[u][v] = G[v][u] = 1;
    }
}

/*
    Deletes the edge between u and v vertices
*/
void deleteEdge(int G[][NMAX], int u, int v){
    if (u < n && v < n){
        G[u][v] = G[v][u] = 0;
    }
}

/*
    Adds the next vertex after n - 1
*/
void addVertex(int G[][NMAX]){
    if (n < NMAX){
        n++;
    }

    for (int i = 0; i < n; i++){
        G[n - 1][i] = G[i][n - 1] = 0;
    }
}

/*
    Deletes the k vertex and moves all the nodes bigger than k
*/
void deleteVertex(int G[][NMAX], int k){
    if (k >= n) return;

    for (int i = k; i < n - 1; i++){
        for (int j = 0; j < n; j++){
            G[i][j] = G[i + 1][j];
        }
    }

    for (int j = k; j < n - 1; j++){
        for (int i = 0; i < n; i++){
            G[i][j] = G[i][j + 1];
        }
    }

    n--;
}

/*
    Prints the adjacency matrix
*/
void printGraph(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    n = 3; 

    addEdge(G, 0, 1);
    addEdge(G, 1, 2);
    addEdge(G, 2, 0);
    
    printGraph();

    deleteVertex(G, 1); 
    printGraph();
    

    addVertex(G);
    addEdge(G, 1, 2);
    printGraph();

    return 0;
}