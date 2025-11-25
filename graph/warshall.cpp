#include <iostream>
using namespace std;
#define NMAX 101

int G[NMAX][NMAX], n;

/*
    Determines if there is a path between nodes using Warshall's Algorithm
*/
void reachMatrix(){
    int B[NMAX][NMAX];

    // B init
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            B[i][j] = G[i][j];
            if (i == j) B[i][j] = 1;
        }
    }

    // Warshall
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (B[i][k] == 1 && B[k][j] == 1)
                    B[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
}
