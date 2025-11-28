#include <iostream>
using namespace std;

struct Node {
    int val;
    Node * next;
};

struct Graph{
    int n;
    Node * adj[101];
};

/*
    Calculates the In-Degree of a node u
*/
int gradInt(Graph &G, int u){
    int cnt = 0;
    
    for (int i = 0; i < G.n; i++){ 
        Node * p = G.adj[i];
        while (p){
			if (p->val == u) cnt++;
            p = p->next;
        }
    }
    
    return cnt;
}

/*
    Calculates the Out-Degree of a node u
*/
int gradExt(Graph &G, int u){
    Node * p = G.adj[u];
    int cnt = 0;
    
    while (p){
        cnt++;
        p = p->next;
    }

    return cnt;
}

int main(){
    Graph G;
    int n, m, cnt = 0, nodes[101], k = 0;
    cin >> n >> m;
    G.n = n;
    for (int i = 0; i < n; i++) G.adj[i] = nullptr;

    for (int i = 0; i < m; i++){
     	int u, v;
        cin >> u >> v;
        
        Node * p = new Node();
        p->val = v;
        p->next = G.adj[u];
        G.adj[u] = p;
    }
    
    /*
        Print the nodes with In-Degree = Out-Degree
    */
    for (int i = 0; i < n; i++){
        if (gradInt(G, i) == gradExt(G, i)){
            cnt++;   
            nodes[k++] = i;
        }
    }
    
    cout << cnt << endl;
    for (int i = 0; i < k; i++){
     	cout <<	nodes[i] << " ";
    }
}