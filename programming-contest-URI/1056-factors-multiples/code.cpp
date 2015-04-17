#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
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
#define INF 10e6
#define FIND(Q, q) (Q.find(q) != Q.end())
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)
 
struct Edge
{
    enum tType
    {
        forward,
        backward
    };
 
    uint x, y, c;
    uint flow;
    tType type;
    Edge *pair;
 
    Edge() : Edge(0, 0) {}
    Edge(uint x, uint y) : Edge(x, y, 0) {}
    Edge(uint x, uint y, uint c) : Edge(x, y, c, forward) {}
    Edge(uint x, uint y, uint c, tType type) : Edge(x, y, c, type, 0) {}
    Edge(uint x, uint y, uint c, tType type, uint flow) : x(x), y(y), c(c),
        flow(flow), type(type), pair(NULL)
    {
    }
 
    bool operator<(const Edge& b) const
    {
        if (this->x == b.x)
            return this->y < b.y;
        else
            return this->x < b.x;
    }
 
    bool operator()(const Edge& a, const Edge& b) const
    {
        if (this->x == b.x)
            return this->y < b.y;
        else
            return this->x < b.x;
    }
 
    string toString() const
    {
        stringstream buffer;
        buffer << "x: " << x << " y: " << y << " c: " << c << " flow: " << flow << endl;
        return buffer.str();
    }
 
    inline Edge *other() { return pair; }
    inline Edge *getPointer() { return this; }
};
 
list< Edge* >* build_path(const map< int, Edge* >& S, int src, int dst)
{
    list< Edge* >* P = new list< Edge* >;
    auto q = S.find(dst);
 
    while (q->second != nullptr)
    {
        P->push_front(q->second);
        q = S.find(q->second->x);
    }
 
    return P;
}
 
list< Edge* >* BFS(vector< vector< Edge* > >& G, int src, int dst)
{
    map< int, Edge* > Q, S;
 
    if (src == dst)
        return new list< Edge* >;
 
    Q.insert(make_pair(src, nullptr));
 
    while (!Q.empty())
    {
        auto q = Q.begin();
 
        if (!FIND(S, q->first))
        {
            S.insert(make_pair(q->first, q->second));
 
            foreach(G[q->first], it)
            {
                if ((*it)->c > 0)
                {
                    if ((*it)->y == dst)
                    {
                        S.insert(make_pair((*it)->y, *it));
                        return build_path(S, src, dst);
                    }
 
                    Q.insert(make_pair((*it)->y, *it));
                }
            }
        }
 
        Q.erase(q);
    }
 
    return nullptr;
}
 
int bottleneck(list< Edge* > *P)
{
    uint min_cap = INF;
 
    foreach(*P, q)
        min_cap = min(min_cap, (*q)->c);
 
    return min_cap;
}
 
void augment(list< Edge* > *P)
{
    int b = bottleneck(P);
    Edge *e;
 
    foreach(*P, it)
    {
        e = *it;
        if (e->type == Edge::forward)
        {
            e->flow += b;
            e->c -= b;
            e->pair->c += b;
        }
        else
        {
            e = e->other();
            e->flow -= b;
            e->c += b;
            e->pair->c -= b;
        }
    }
}
 
int max_flow(vector< vector< Edge* > >& G, int src, int dst)
{
    list< Edge * > *P;
    int flow = 0;
 
    while (P = BFS(G, src, dst))
    {
        augment(P);
    }
 
    foreach(G[src], edge)
    {
        Edge *e = *edge;
        flow += e->flow;
    }
 
    return flow;
}
 
class Graph
{
public:
    vector< vector< Edge* > > adj;
 
    void Insert(int x, int y, int c)
    {
        adj[x].push_back(new Edge(x, y, c, Edge::forward));
        adj[y].push_back(new Edge(y, x, 0, Edge::backward));
        adj[x].back()->pair = adj[y].back();
        adj[y].back()->pair = adj[x].back();
    }
};
 
int main()
{
    int T;
 
    scanf("%d\n", &T);
    for (int i = 1; i <= T; ++i)
    {
        int num_numbers;
        vector< int > A, B;
        Graph G;
        int s_index, t_index;
 
        scanf("%d", &num_numbers);
        A.resize(num_numbers);
 
        for (int j = 0; j < num_numbers; ++j)
        {
            int x;
            scanf("%d", &x);
            A[j] = x;
        }
 
        scanf("%d", &num_numbers);
        B.resize(num_numbers);
 
        for (int j = 0; j < num_numbers; ++j)
        {
            int x;
            scanf("%d", &x);
            B[j] = x;
        }
 
        G.adj.resize(A.size() + B.size() + 2);
        s_index = A.size() + B.size();
        t_index = A.size() + B.size() + 1;
 
        for (int j = 0; j < A.size(); ++j)
        {
            for (int k = 0; k < B.size(); ++k)
            {
                if (A[j] == 0)
                {
                    if (B[k] == 0)
                        G.Insert(j, k + A.size(), 1);
                } else if (B[k] % A[j] == 0)
                    G.Insert(j, k + A.size(), 1);
            }
        }
 
        for (int j = 0; j < A.size(); ++j)
            G.Insert(s_index, j, 1);
 
        for (int j = 0; j < B.size(); ++j)
            G.Insert(A.size() + j, t_index, 1);
 
        printf("Case %d: %d\n", i, max_flow(G.adj, s_index, t_index));
    }
}