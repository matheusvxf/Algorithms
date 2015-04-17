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
#define INF (long long int)1e15
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
        parent[y] = x;
        level[y] = level[x] + 1;
        adj[x].push_back(new Edge(x, y, dst));
        adj[y].push_back(new Edge(y, x, dst));
    }

    void LowerCommonAncestorInit()
    {
        P.resize(adj.size());
        int size = adj.size();;
        int log_size = ceil(log(size) / log(2));

        for (int i = 0; i < size; ++i)
        {
            P[i].resize(log_size);
            fill(all(P[i]), -1);
        }

        for (int i = 0; i < size; ++i)
            P[i][0] = parent[i];


        for (int j = 1; 1 << j < size; ++j)
        {
            for (int i = 0; i < size; ++i)
            {
                P[i][j] = P[P[i][j - 1]][j - 1];
            }
        }
    }

    int LowerCommonAncestor(int p, int q)
    {
        int tmp, log, i;

        // if p is situated on a lower level than q then we swap them
        if (level[p] < level[q])
            tmp = p, p = q, q = tmp;

        // we compute the value of [log(L[p)]
        for (log = 1; 1 << log <= level[p]; log++);
        log--;

        // we find the ancestor of node p situated on the same level
        // with q using the values in P
        for (i = log; i >= 0; i--)
        if (level[p] - (1 << i) >= level[q])
            p = P[p][i];

        if (p == q)
            return p;

        //we compute LCA(p, q) using the values in P
        for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

        return parent[p];
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

vector< long long int >* Dijkstra(Graph& G, int src)
{
    int num_nodes = G.size;
    vector< long long int > &distance = *new vector< long long int >(num_nodes);
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

inline int Log2(int x)
{
    int counter = 0;
    while (x >>= 1) counter++;
    return counter;
}

class Ancestor
{
public:
    unordered_set< long long int > queries;
    unordered_set< int > destinations;
};

int main()
{
    while (scanf("%d\n", &N) && N != 0)
    {
        int Q, src, dst, ancestor;
        Graph G(N);
        vector< long long int > queries;

        for (int i = 1; i <= N - 1; ++i)
        {
            int A;
            long long int L;
            
            scanf("%d %lld\n", &A, &L);
            G.Insert(A, i, L);
        }

        vector< long long int > &distance = *Dijkstra(G, 0);
        G.LowerCommonAncestorInit();
        scanf("%d\n", &Q);

        queries.resize(Q);
        scanf("%d %d\n", &src, &dst);
        ancestor = G.LowerCommonAncestor(src, dst);
        printf("%lld", distance[src] + distance[dst] - 2 * distance[ancestor]);
        for (int i = 1; i < Q; ++i)
        {
            scanf("%d %d\n", &src, &dst);
            ancestor = G.LowerCommonAncestor(src, dst);
            printf(" %lld", distance[src] + distance[dst] - 2 * distance[ancestor]);
        }

        printf("\n");
    }
}