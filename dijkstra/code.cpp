#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <list>
#include <set>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <stdio.h>

using namespace std;

#define uint unsigned int
#define INF 1000000
#define FIND(Q, q) (Q.find(q) != Q.end())
#define all(Q) Q.begin(), Q.end()
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)

struct Edge
{
    int x, y, cost;
    Edge *oposite_direction;

    Edge() : Edge(0, 0) {}
    Edge(int x, int y) : Edge(x, y, 0) {}
    Edge(int x, int y, int cost) : x(x), y(y), cost(cost), oposite_direction(nullptr) {}
};

class Graph
{
public:
    vector< vector< Edge* > > adj;

    Graph(int size) : adj(size) {}

    void Insert(int x, int y)
    {
        adj[x].push_back(new Edge(x, y));
        adj[y].push_back(new Edge(y, x));
        adj[x].back()->oposite_direction = adj[y].back();
        adj[y].back()->oposite_direction = adj[x].back();
    }

    void AddEdgeCost(int node, int cost)
    {
        for (int i = 0, size = adj[node].size(); i < size; ++i)
        {
            adj[node][i]->cost += cost;
        }
    }
};

class Node
{
public:
    int id;
    int dst;

    Node() : Node(0) {}
    Node(int id) : Node(id, 0) {}
    Node(int id, int dst) : id(id), dst(dst) {}

    bool operator<(const Node& a) const
    {
        if (this->id == a.id)
            return false;
        if (this->dst < a.dst)
            return true;
        else if (this->dst > a.dst)
            return false;
        else
            return this->id < a.id;
    }
};

int Dijkstra(Graph G, int src, int dst)
{
    int num_nodes = G.adj.size();
    vector< int > snipers(num_nodes);
    set< Node > Q;

    fill(all(snipers), INF);

    Q.insert(Node(src, 0));
    snipers[src] = 0;

    for (int i = 0; i < num_nodes; ++i)
        Q.insert(Node(i, INF));

    while (1)
    {
        auto it = Q.begin();
        Node node = *it;

        Q.erase(it);
        if (node.id == dst)
            return node.dst;
        if (node.dst == INF)
            return INF;

        for (int i = 0, size = G.adj[node.id].size(); i < size; ++i)
        {
            Edge *e = G.adj[node.id][i];
            auto it = Q.find(Node(e->y, snipers[e->y]));

            if (it != Q.end() && node.dst + e->cost < it->dst)
            {
                snipers[e->y] = node.dst + e->cost;
                Q.erase(it);
                Q.insert(Node(e->y, snipers[e->y]));
            }
        }
    }
}

int main()
{
    int N, M, K;
    float P;

    while (scanf("%d %d %d %f\n", &N, &M, &K, &P) != EOF)
    {
        Graph G(N);
        int A, source, destination;
        int snipers;
        float probability;
        vector< int > sniper_by_pos(N);

        for (int i = 0; i < M; ++i)
        {
            int x, y;
            scanf("%d %d\n", &x, &y); x--; y--;
            G.Insert(x, y);
        }

        scanf("%d", &A);

        for (int i = 0; i < A; ++i)
        {
            int position;

            scanf("%d", &position); position--;
            G.AddEdgeCost(position, 1);
            sniper_by_pos[position]++;
        }

        scanf("%d %d\n", &source, &destination); source--; destination--;

        snipers = Dijkstra(G, source, destination);
        snipers += sniper_by_pos[destination];

        if (snipers > K)
            probability = 0;
        else
        {
            probability = 1;
            while (snipers--)
                probability *= P;
        }
        printf("%.3f\n", probability);
    }
}