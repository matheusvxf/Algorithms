#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <string.h>

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
    string s1, s2;
    vector< vector< Edge * > > G;
    vector< pair< int, int> > moves{ { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 }, { 1, 2 }, { 2, 1 }, { -1, 2 }, { -2, 1 } };

    G.resize(8 * 8);

    for (int line = 0; line < 8; ++line)
    {
        for (int column = 0; column < 8; ++column)
        {
            foreach(moves, it)
            {
                pair<int, int> move = *it;
                if (line + move.first >= 0 && line + move.first < 8 && column + move.second >= 0 && column + move.second < 8)
                    graph_insert(G, line * 8 + column, (line + move.first) * 8 + column + move.second);
            }
        }
    }

    while (cin >> s1 >> s2)
    {
        int moves, src, dst;

        src = s1[0] - 'a' + (s1[1] - '1') * 8;
        dst = s2[0] - 'a' + (s2[1] - '1') * 8;
        
        moves = BFS(G, src, dst);

        printf("To get from %s to %s takes %d knight moves.\n", s1.c_str(), s2.c_str(), moves);
    }
}
