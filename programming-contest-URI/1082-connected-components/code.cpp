#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

#define uint unsigned int
#define FIND(Q, q) (Q.find(q) != Q.end())
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)

struct Edge {
	uint x, y, c;

    Edge(uint x, uint y) : Edge(x, y, 0) {}
	Edge(uint x, uint y, uint c) : x(x), y(y), c(c) {}

	bool operator<(const Edge& b) const {
		return c < b.c;
	}
	bool operator()(const Edge& a, const Edge& b) const {
		return a.c < b.c;
	}
};

set< int > A;
set< int > S;
int n_component;

int BFS(const vector< vector< Edge* > >& G, int src) {
    deque< int > Q;

	Q.push_back(src);

	while(!Q.empty()) {
		auto q = Q.front();
        
        foreach(G[q], neighbor)
        {
            Edge *e = *neighbor;
            if (FIND(A, e->y))
            {
                Q.push_back(e->y);
            }
        }

        auto it = A.find(q);
        if (it != A.end())
            A.erase(it);
        S.insert(q);
		Q.pop_front();
	}

	return -1;
}

void graph_insert(vector< vector< Edge* > >& G, int x, int y)
{
    G[x].push_back(new Edge(x, y));
}

void connected_component(vector< vector< Edge* > >& G)
{
    n_component = 0;

    while (!A.empty())
    {
        S.clear();
        BFS(G, *A.begin());
        
        foreach(S, it)
        {
            cout << (char)(*it + 'a') << ",";
        }
        cout << endl;
        n_component++;
    }
    printf("%d connected components\n\n", n_component);
}

int main() {
	uint N, V, E;
    char x, y;
	vector< vector< Edge* > > G;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> V >> E;
        G.clear();
        A.clear();
        S.clear();
        G.resize(V);
        for (int j = 0; j < V; ++j)
            A.insert(j);
        
        for (int j = 0; j < E; ++j)
        {
            cin >> x >> y;

            graph_insert(G, x - 'a', y - 'a');
            graph_insert(G, y - 'a', x - 'a');
        }

        printf("Case #%d:\n", i + 1);
        connected_component(G);
    }
}
