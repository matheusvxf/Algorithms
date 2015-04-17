#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
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

int BFS(const vector< vector< Edge* > >& G, int src, int dst) {
    deque< pair< int, int > > Q;
    int *lbl = new int[G.size()];
    memset(lbl, 0, sizeof(int)* G.size());

	if(src == dst)
		return 0;

	Q.push_back(make_pair(src, 0));

	while(!Q.empty()) {
		auto q = Q.front();
        
        foreach(G[q.first], neighbor)
        {
            Edge *e = *neighbor;
            if (lbl[e->y] == 0)
            {
                lbl[e->y]++;
                if (e->y == dst)
                    return q.second + 1;
                Q.push_back(make_pair(e->y, q.second + 1));
            }
        }

		Q.pop_front();
	}

	return -1;
}

void graph_insert(vector< vector< Edge* > >& G, int x, int y)
{
    G[x].push_back(new Edge(x, y));
}

int main() {
	uint N, A, B, C, D, P, x0, y0, x1, y1;
    int res;
	vector< vector< Edge* > > G;

	while(cin >> N && N != 0) {
        G.clear();
        G.resize(N * N);

		for(int y = N-1; y >= 0; --y) {
			for(int x = 0; x < N; ++x) {
				cin >> A >> B >> C >> D;
                if (A)
                    graph_insert(G, N * y + x, N * (y + 1) + x);
                if (B)
                    graph_insert(G, N * y + x, N * (y - 1) + x);
                if (C)
                    graph_insert(G, N * y + x, N * y + (x - 1));
                if (D)
                    graph_insert(G, N * y + x, N * y + (x + 1));
			}
		}

        cin >> P;
        for (uint i = 0; i < P; ++i)
        {
            cin >> x0 >> y0 >> x1 >> y1;
            res = BFS(G, y0 * N + x0, y1 * N + x1);

            if (res == -1)
                cout << "Impossible" << endl;
            else
                cout << res << endl;
        }
        cout << endl;
	}
}
