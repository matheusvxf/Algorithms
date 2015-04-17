#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

#define uint unsigned int
#define FIND(Q, q) (Q.find(q) != Q.end())
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)
#define INF ((int)10e6)
struct Edge {
	uint x, y;
    bool reversed;

    Edge(uint x, uint y) : Edge(x, y, false) {}
	Edge(uint x, uint y, bool r) : x(x), y(y), reversed(r) {}
};

class City
{
public:
    int dst;
    int reachable;

    City() : dst(0), reachable(0) {}

    static int min_dst;

    static void mark_connectivity(unordered_map< int, City* >& S, int city_id, int dst)
    {
        City *c;

        if (FIND(S, city_id))
            c = S[city_id];
        else
        {
            c = new City();
            S.insert(make_pair(city_id, c));
        }
        c->dst += dst;
        c->reachable++;

        if (c->reachable == 2 && c->dst < min_dst)
        {
            min_dst = c->dst;
        }
    }

    static void reset()
    {
        min_dst = INF;
    }
};

int City::min_dst = INF;

void BFS(const vector< Edge* >& G, unordered_map< int, City* >& S, int src)
{
    deque< int > Q;
    int *lbl = new int[G.size()];

    fill(lbl, lbl + G.size(), -1);

    lbl[src] = 0;
    Q.push_back(src);

    City::mark_connectivity(S, src, 0);

    while (!Q.empty())
    {
        auto q = Q.front();
        Edge *e = G[q];
        
        Q.pop_front();

        if (lbl[e->y] == -1)
        {
            lbl[e->y] = lbl[e->x] + 1;

            City::mark_connectivity(S, e->y, lbl[e->y]);
            
            Q.push_back(e->y);
        }
    }

    delete[]lbl;
}

int join_couples(vector< Edge*> &G, int x, int y)
{
    int res = 2;
    unordered_map< int, City* > S;

    City::reset();

    BFS(G, S, x);
    BFS(G, S, y);

    foreach(S, it) delete it->second;

    return (City::min_dst == INF ? -1 : City::min_dst);
}

inline void graph_insert(vector< Edge* >& G, int x, int y, bool reversed = false)
{
    G[x] = new Edge(x, y, false);
}

int main() {
    uint N, F, Q, A, B;

    while (scanf("%d", &N) != EOF)
    {
        vector< Edge* > G(N);

        for (int i = 0; i < N; ++i)
        {
            scanf("%d", &F);
            graph_insert(G, i, F - 1);
        }

        scanf("%d", &Q);
        for (int i = 0; i < Q; ++i)
        {
            scanf("%d %d", &A, &B);
            A--; B--;

            printf("%d\n", join_couples(G, A, B));
        }

        foreach(G, it) delete *it;
	}
}
