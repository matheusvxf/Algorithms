#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

#define DEBUG 0
#define all(Q) Q.begin(), Q.end()
#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)
#define FIND(S, x) (S.find(x) != S.end())

class Edge {
public:
	int x, y, weight, sub_tree;
	static int count;

	Edge() : Edge(0, 0, 0) {}
    Edge(int x, int y, int weight) : x(x), y(y), weight(weight), sub_tree(count++) {}

	bool operator()(const Edge& a, const Edge& b) const
    {
        return (*this)(&a, &b);
	}

    inline bool operator()(const Edge* a, const Edge* b) const
    {
        return a->weight < b->weight;
    }

    inline int Other(int node)
    {
        if (node == x)
            return y;
        else
            return x;
    }
} edge_compare;

class Graph
{
public:
    vector< vector< Edge* > > adj;
    vector< Edge* > E;
    int weight_sum;

    Graph() : weight_sum(0) {}

    inline void SetNumNodes(int num_nodes) { adj.resize(num_nodes); }
    inline void SetNumEdges(int num_edges) { E.resize(num_edges); }

    void Insert(int a, int b, int weight)
    {
        Edge *e = new Edge(a, b, weight);

        E.push_back(e);
        adj[a].push_back(e);
        adj[b].push_back(e);
        weight_sum += weight;
    }

    int MinSpanningTree()
    {
        multiset< Edge*, Edge > Q;
        Edge *e;
        set< int > S;

        e = E.back();
        Q.insert(all(adj[e->x]));
        S.insert(e->x);

        while (!Q.empty())
        {
            auto q = *Q.begin();
            bool found = FIND(S, q->x);
            int node = q->x;

            Q.erase(Q.begin());
            if (found)
            {
                found = FIND(S, q->y);
                node = q->y;
            }

            if (!found)
            {
                S.insert(node);
                weight_sum -= q->weight;

                foreach(adj[node], it)
                {
                    Edge *e = *it;
                    int neighbor = e->Other(node);
                    
                    if (!FIND(S, neighbor))
                        Q.insert(e);
                }
            }

        }
        return weight_sum;
    }
};

int Edge::count = 0;

int total;
int *S;
int *D;

int main() {
	int m, n, x, y, z;

    while (cin >> m >> n && (m != 0 || n != 0))
    {
        Graph G;

        G.SetNumNodes(m);
        G.SetNumEdges(n);

		for(int i = 0; i < n; ++i) {
			cin >> x >> y >> z;
            G.Insert(x, y, z);
		}

		total = G.MinSpanningTree();

		cout << total << endl;
	}
}
