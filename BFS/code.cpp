#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

#define FIND(Q, q) (Q.find(q) != Q.end())
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)

struct Edge {
	uint x, y, c;

	Edge(uint x, uint y, uint c) : x(x), y(y), c(c) {}

	bool operator<(const Edge& b) const {
		return c < b.c;
	}
	bool operator()(const Edge& a, const Edge& b) const {
		return a.c < b.c;
	}
};

vector< int >* build_path(map< int, int >& S, int src, int dst) {
	vector< int >* P = new vector< int >;
	auto q = S.find(dst);

	while(q != S.end()) {
		P->push_back(q->first);
		q = S.find(q->second);
	}

	return P;
}

vector< int >* BFS(const vector< multiset< Edge > >& G, int src, int dst) {
	map< int, int > Q, S;

	if(src == dst)
		return new vector< int >(src);

	Q.insert(make_pair(src, -1));

	while(!Q.empty()) {
		auto q = Q.begin();

		if(!FIND(S, q->first)) {
			S.insert(*q);

			foreach(G[q->first], it) {
				if(it->y == dst) {
					S.insert(make_pair(it->y, q->first));
					return build_path(S, src, dst);
				}

				Q.insert(make_pair(it->y, q->first));
			}
		}

		Q.erase(q);
	}

	return nullptr;
}

int main() {
	uint I, N, E, x, y, z;
	vector< multiset< Edge > > G;
	vector< int > *P;

	cin >> I;

	for(register uint i = 0; i < I; ++i) {
		cin >> N  >> E;
		G.clear();
		G.resize(N);

		for(register uint j = 0; j < E; ++j) {
			cin >> x >> y >> z;
			G[x].insert(Edge(x, y, z));
			G[y].insert(Edge(y, x, z));
		}

		P = BFS(G, 0, 4);

		foreach(*P, it)
			cout << *it << " ";
		cout << endl;
	}
}
