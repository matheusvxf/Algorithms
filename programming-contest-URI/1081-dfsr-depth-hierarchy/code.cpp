#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int **adj;
int *lbl;
int V;
int depth;
bool first;

#define foreach(A, it) for(auto it = A.begin(); it != A.end(); ++it)
#define NVISITED 0
#define VISITED 1
#define INPATH 2
#define print_white(depth) \
    for(register uint i = 0; i < depth; ++i) \
        cout << "  ";

void dfs(int v) {
    bool flag = false;
    if(!first) {
        if(lbl[v] == 0) {
            printf(" pathR(G,%d)\n", v);
        } else {
            cout << endl;
        }
    }
    first = false;
    lbl[v]++;

    first = false;
    for(uint w = 0; w < V; ++w) {
        if(adj[v][w] == 1) {
            if(lbl[w] == 0) {
                print_white(depth);
                printf("%d-%d", v, w);
                depth++;
                dfs(w);
                depth--;
                flag = true;
            } else {
                print_white(depth);
                printf("%d-%d\n", v, w);
            }
        }
    }

    if(flag && depth == 1)
        cout << endl;
}

int main(){
    int N, E, x, y, f_x, f_y;

    cin >> N;

    for(register uint i = 0; i < N; ++i) {
        cin >> V >> E;
        adj = new int*[V];
        lbl = new int[V];
        memset(lbl, 0, sizeof(int) *  V);
        for(register uint j = 0; j < V; ++j) {
            adj[j] = new int[V];
            memset(adj[j], 0, sizeof(int) * V);
        }
        
        printf("Caso %d:\n", i + 1);

        cin >> f_x >> f_y;
        adj[f_x][f_y] = 1;
        for(register uint j = 1; j < E; ++j) {
            cin >> x >> y;
            adj[x][y] = 1;
        }

        for(register uint j = 0; j < V; ++j) {
            depth = 1;
            first = true;
            if(lbl[j] == 0) {
                dfs(j);
            }
        }

        for(register uint j = 0; j < V; ++j) delete[]adj[j];
        delete[]adj;
        delete[]lbl;
    }
}
