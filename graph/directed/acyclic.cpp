#include <iostream>
using namespace std;

struct Node {
    int val;
    Node * next;
};

struct Graph{
    int n, viz[101] = {0}, inStack[101] = {0};
    Node * adj[101] = {nullptr};
};

bool hasCycle(Graph &G, int u){
    G.viz[u] = 1;
    G.inStack[u] = 1;

    Node * p = G.adj[u];
    while (p){
        if (G.viz[p->val] == 0){
            if (hasCycle(G, p->val)) return true;
        } else if (G.inStack[p->val] == 1) return true;

        p = p->next;
    }

    G.inStack[u] = 0;
    return false;
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
    bool cycle = false;

    for(int i = 0; i < n; i++) {
        if(G.viz[i] == 0) {
            if(hasCycle(G, i)) {
                cycle = true;
                break;
            }
        }
    }

    if (cycle) cout << "It has a cycle";
    else cout << "It doesn't have a cycle";

    return 0;
}