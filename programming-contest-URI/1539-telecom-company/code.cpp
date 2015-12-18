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
    int x, y;
    double cost;
    Edge *oposite_direction;

    Edge() : Edge(0, 0) {}
    Edge(int x, int y) : Edge(x, y, 0) {}
    Edge(int x, int y, double cost) : x(x), y(y), cost(cost), oposite_direction(nullptr) {}
};

class Graph
{
public:
    vector< vector< Edge* > > adj;

    Graph(int size) : adj(size) {}

    void Insert(int x, int y, double cost)
    {
        adj[x].push_back(new Edge(x, y, cost));
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
    double dst;

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

double Dijkstra(Graph G, int src, int dst)
{
    int num_nodes = G.adj.size();
    vector< double > snipers(num_nodes);
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

double distance(double x_1, double y_1, double x_2, double y_2)
{
    return sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
}

int main()
{
    int N;

    while (scanf("%d\n", &N) && N != 0)
    {
        Graph G(N);
        vector< int* > Q;
        int C;

        for (int i = 0; i < N; ++i)
        {
            int x, y, r;
            scanf("%d %d %d\n", &x, &y, &r);
            int *a = new int[3];
            a[0] = x; a[1] = y; a[2] = r;
            Q.push_back(a);
        }

        for (int i = 0, size = Q.size(); i < size; ++i)
        {
            for (int j = 0, size = Q.size(); j < size; ++j)
            {
                if (i != j)
                {
                    double dst = distance(Q[i][0], Q[i][1], Q[j][0], Q[j][1]);
                    if (dst <= Q[i][2])
                    {
                        G.Insert(i, j, dst);
                    }
                }
            }
        }

        scanf("%d\n", &C);

        for (int i = 0; i < C; ++i)
        {
            int A1, A2;
            scanf("%d %d\n", &A1, &A2); A1--; A2--;
            double dst = Dijkstra(G, A1, A2);
            printf("%d\n", (dst == INF ? -1 : (int)floor(dst)));
        }

    }
}