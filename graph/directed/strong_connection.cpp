#include <iostream>
using namespace std;

struct Node {
    int val;
    Node * next;
};

struct Graph{
    int n, viz[101] = {0};
    Node * adj[101] = {nullptr};
};

void DFS(Graph &G, int u){
    G.viz[u] = 1;
    Node * p = G.adj[u];

    while (p){
        if (!G.viz[p->val]) DFS(G, p->val);
        p = p->next;
    }
    
}

bool strongConnected(Graph &G){
    for (int i = 0; i < G.n; i++){
        for (int j = 0; j < G.n; j++) G.viz[j] = 0;

        DFS(G, i);

        for (int j = 0; j < G.n; j++){
            if (G.viz[j] == 0) return 0;
        }
    }

    return 1;
}

int main(){
    Graph G;
    int n, m, cnt = 0, nodes[101], k = 0;
    cin >> n >> m;
    G.n = n;

    for (int i = 0; i < m; i++){
     	int u, v;
        cin >> u >> v;
        
        Node * p = new Node();
        p->val = v;
        p->next = G.adj[u];
        G.adj[u] = p;
    }
}