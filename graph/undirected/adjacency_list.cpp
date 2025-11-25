#include <iostream>
using namespace std;
#define NMAX 101

struct Node{
    int val;
    Node * next;
};

struct Graph{
    int n;
    Node * adj[NMAX];
};

/*
    Initializes graph
*/
void initGraph(Graph &G, int n){
    G.n = n;

    for (int i = 0; i < n; i++){
        G.adj[i] = NULL;
    }
}

/*
    Adds an edge between u and v
*/
void addEdge(Graph &G, int u, int v){
    if (u >= G.n || v >= G.n) return;

    Node * n1 = new Node();
    n1->val = v;
    n1->next = G.adj[u];
    G.adj[u] = n1;
}

/*
    Add both edges for undirected graphs
*/
void addEdgeUndirected(Graph &G, int u, int v){
    addEdge(G, u, v);
    addEdge(G, v, u);
}

/*
    Deletes the edge between u and v
*/
void deleteEdge(Graph &G, int u, int v){
    if (u >= G.n) return;

    Node * current = G.adj[u];
    Node * prev = NULL;

    while (current && current->val != v){
        prev = current;
        current = current->next;
    }

    if (current == NULL) return;

    if (prev == NULL) G.adj[u] = current->next;
    else prev->next = current->next;

    delete current;
}

/*
    Delete both edges for undirected graphs
*/
void deleteEdgeUndirected(Graph &G, int u, int v){
    deleteEdge(G, u, v);
    deleteEdge(G, v, u);
}

/*
    Adds a vertex at the end of the graph array
*/
void addVertex(Graph &G){
    if (G.n < NMAX){
        G.adj[G.n] = NULL;
        G.n++;
    }
}

void printGraf(Graph &G) {
    for (int i = 0; i < G.n; i++) {
        cout << i << ": ";
        Node * p = G.adj[i];
        while (p != NULL) {
            cout << p->val << " -> ";
            p = p->next;
        }
        cout << "NULL" << endl;
    }
}

int main() {
    Graph G;
    initGraph(G, 4); 

    addEdge(G, 0, 1);
    addEdge(G, 0, 3);
    addEdge(G, 1, 2);
    addEdge(G, 3, 2); 

    printGraf(G);
    
    addVertex(G);
    printGraf(G);

    return 0;
}