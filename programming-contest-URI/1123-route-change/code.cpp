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
#define INF (int)1e9
#define FIND(Q, q) (Q.find(q) != Q.end())
#define all(Q) (Q).begin(), (Q).end()
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)

struct Edge
{
    int x, y;
    long long int dst;

    Edge() : Edge(0, 0) {}
    Edge(int x, int y) : Edge(x, y, 1) {}
    Edge(int x, int y, long long int dst) : x(x), y(y), dst(dst) {}
};

static int N;

inline long long int query(long long int a, long long int b)
{
    return a * (long long int) N + b;
}

inline long long int query_src(long long int a)
{
    return a / N;
}

inline long long int query_dst(long long int a)
{
    return a % N;
}

class Graph
{
public:
    vector< vector< Edge* > > adj;
    vector< vector< int > > P;
    vector< int > parent;
    vector< int > level;
    vector< long long int > distance;
    int size;
    
    Graph(int size) : adj(size), parent(size), level(size), size(size), distance(size) {
        level[0] = 0;
        fill(all(distance), INF);
    }

    void Insert(int x, int y, long long int dst)
    {
        adj[x].push_back(new Edge(x, y, dst));
    }
};

class Node
{
public:
    int id;
    long long int dst;

    Node() : Node(0) {}
    Node(int id) : Node(id, 0) {}
    Node(int id, long long int dst) : id(id), dst(dst) {}

    bool operator()(const Node& a, const Node& b) const
    {
        if (a.dst < b.dst)
            return true;
        else if (a.dst > b.dst)
            return false;
        else
            return a.id < b.id;
    }
};

vector< int >* Dijkstra(Graph& G, int src)
{
    int num_nodes = G.size;
    vector< int > &distance = *new vector< int >(num_nodes);
    set< Node, Node > Q;

    fill(all(distance), INF);

    for (int i = 0; i < num_nodes; ++i)
    if (i != src)
        Q.insert(Node(i, INF));

    Q.insert(Node(src, 0));
    distance[src] = 0;

    while (!Q.empty())
    {
        auto it = Q.begin();
        Node node = *it;

        Q.erase(it);

        for (int i = 0, size = G.adj[node.id].size(); i < size; ++i)
        {
            Edge *e = G.adj[node.id][i];
            auto it = Q.find(Node(e->y, distance[e->y]));

            if (it != Q.end() && node.dst + e->dst < it->dst)
            {
                distance[e->y] = node.dst + e->dst;
                Q.erase(it);
                Q.insert(Node(e->y, distance[e->y]));
            }
        }
    }

    return &distance;
}

#ifndef ONLINE_JUDGE
void create_test();
#endif

int main()
{
    int N, M, C, K;

#ifndef ONLINE_JUDGE
    create_test();
#endif

    while (scanf("%d %d %d %d\n", &N, &M, &C, &K) && N != 0)
    {
        int dst = C - 1;
        Graph G(N);

        for (int i = 0; i < M; ++i)
        {
            int s, d, toll, tmp;
            scanf("%d %d %d\n", &s, &d, &toll);
            tmp = s; s = min(s, d); d = max(tmp, d);

            if (s >= dst)
            {
                G.Insert(s, d, toll);
                G.Insert(d, s, toll);
            }
            else
            {
                G.Insert(d, s, toll);
                if (s == d - 1)
                    G.Insert(s, d, toll);
            }
        }

        vector< int > &distance_start = *Dijkstra(G, K);

        printf("%d\n", distance_start[dst]);
    }
}

#ifndef ONLINE_JUDGE

#include <fstream>
void create_test()
{
    int num_test = 1;
    int N, M, C, K;
    fstream stream("test.in", fstream::out);
    srand(time(NULL));

    while (num_test--)
    {
        N = rand() % (40 - 4) + 4;
        M = rand() % (N * (N - 1) / 2 + 1 - 3) + 3;
        C = rand() % (N - 1 - 2 + 1) + 2;
        K = rand() % (N - 1 - C + 1) + C;

        stream << N << " " << M << " " << C << " " << K << endl;
        for (int i = 0; i < M; ++i)
        {
            int U, V, P;

            U = rand() % (N - 1 + 1);
            V = rand() % (N - 1 + 1);
            P = rand() % 251;

            stream << U << " " << V << " " << P << endl;
        }
    }

    stream << "0 0 0 0" << endl;
}
#endif