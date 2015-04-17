#include <iostream>
#include <set>
#include <map>
#include <string.h>

using namespace std;

#define INF 10000

class Neighbor {
public:
    uint id;
    uint dst;

    Neighbor() : Neighbor(0, 0) {}
    Neighbor(uint id, uint dst) : id(id), dst(dst) {}

    bool operator() (const Neighbor& a, const Neighbor &b) const {
        if(a.dst == b.dst)
            return a.id < b.id;
        else
            return a.dst < b.dst;
    }
};

int dijkstra(int **D, uint N, int src, int dst) {
    int *dist = new int[N], i = 1;
    set<Neighbor, Neighbor> Q;
    map<uint, uint> S;
    memset(dist, 10000, sizeof(int) * N);

    for(register uint i = 0; i < N; ++i)
        S[i] = INF;

    Q.insert(Neighbor(src, 0));
    S[src] = 0;

    while(Q.empty() == false) {
        auto it = Q.begin();

        if(it->id == dst)
            return it->dst;

        for(register int i = 0; i < N; ++i) {
            if(it->dst + D[it->id][i] < S[i]) {
                auto q = Q.find(Neighbor(i, S[i]));
                Neighbor n;

                if(q == Q.end()) {
                    n.id = i;
                } else {
                    n = *q;
                    Q.erase(q);
                }
                n.dst = it->dst + D[it->id][i];
                Q.insert(n);
                S[i] = n.dst;
            }
        }

        Q.erase(it);
    }
    
    delete[]dist;

    return -1;
}

int main(){
    int N, E, X, Y, H, K, O, D, tmp;
    int **graph;

    while(cin >> N >> E && (N != 0 || E != 0)) {
        graph = new int*[N];
        for(register uint i = 0; i < N; ++i) {
            graph[i] = new int[N];
            for(register uint j = 0; j < N; ++j)
                graph[i][j] = INF;
        }

        for(register uint i = 0; i < N; ++i)
            graph[i][i] = 0;

        for(register uint i = 0; i < E; ++i) {
            cin >> X >> Y >> H;
            X--; Y--;
            graph[X][Y] = H;
            if(graph[Y][X] != INF)
                graph[X][Y] = graph[Y][X] = 0;
        }

        cin >> K;
        for(register uint i = 0; i < K; ++i) {
            cin >> O >> D;
            tmp = dijkstra(graph, N, O - 1, D - 1);
            if(tmp == -1)
                cout << "Nao e possivel entregar a carta" << endl;
            else 
                cout << tmp << endl;
        }

        cout << endl;

        for(register uint i = 0; i < N; ++i)
            delete[]graph[i];
        delete[]graph;
    }
}
