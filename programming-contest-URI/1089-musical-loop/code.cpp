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
    int N, h;

    while(cin >> N && N != 0) {
        int last = (int)-10e5, num_peak = 0, h_1, h_2;
        bool increasing = true;

        cin >> h_1 >> h_2;
        if(h_2 > h_1)
            increasing = true;
        else
            increasing = false;
        last = h_2;
        for(int i = 2; i < N; ++i) {
            cin >> h;

            if(increasing) {
                if(h < last) {
                    num_peak++;
                    increasing = false;
                }
            } else {
                if(h > last) {
                    num_peak++;
                    increasing = true;
                }
            }
            last = h;
        }

        if(increasing) {
            if(h_1 < last) {
                num_peak++;
                increasing = false;
            }
        }
        else {
            if(h_1 > last) {
                num_peak++;
                increasing = true;
            }
        }
        last = h_1;

        if(increasing) {
            if(h_2 < last) {
                num_peak++;
                increasing = false;
            }
        }
        else {
            if(h_2 > last) {
                num_peak++;
                increasing = true;
            }
        }


        printf("%d\n", num_peak);
    }
}
