#include <iostream>
#include <queue>
using namespace std;

#define NMAX 101

int G[NMAX][NMAX], n, m;
bool viz[NMAX];

/*
    Implements a Breadth-First Search using an adjacency matrix.
    Traverses level by level with a queue.
*/
void bfs(int start){
    queue <int> q;

    q.push(start);
    viz[start] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 1; i <= n; i++){
            if (a[node][i] == 1 && !viz[i]){
                viz[i] = 1;
                q.push(i);
            }
        }
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
    bfs(start);
}