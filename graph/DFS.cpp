#include <iostream>
using namespace std;

#define NMAX 101

int G[NMAX][NMAX], n, m;
bool viz[NMAX];

/*
    Implements a Depth-First Search using an adjacency matrix.
    Traverses the graph by exploring branches as deep as possible using recursion.
*/
void dfs(int start){
    viz[start] = 1;
    cout << start << " ";
    for (int i = 1; i <= n; i++){
        if (a[start][i] == 1 && !viz[i])
            dfs(i);
    }
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }

    int start;
    cin >> start;
    dfs(start);
}