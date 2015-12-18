#define _CRT_SECURE_NO_WARNINGS
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
 
struct Edge {
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
        flow(flow), type(forward), pair(NULL) {}
 
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
 
    string toString() const {
        stringstream buffer;
        buffer << "x: " << x << " y: " << y << " c: " << c << " flow: " << flow << endl;
        return buffer.str();
    }
 
    inline Edge *other() { return pair;  }
    inline Edge *getPointer() { return this; }
};
 
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
 
list< Edge* >* build_path(const map< int, Edge* >& S, int src, int dst) {
    list< Edge* >* P = new list< Edge* >;
    auto q = S.find(dst);
 
    while(q->second != nullptr) {
        P->push_front(q->second);
        q = S.find(q->second->x);
    }
 
    return P;
}
 
list< Edge* >* BFS(vector< vector< Edge* > >& G, int src, int dst) {
    map< int, Edge* > Q, S;
 
    if(src == dst)
        return new list< Edge* >;
 
    Q.insert(make_pair(src, nullptr));
 
    while(!Q.empty()) {
        auto q = Q.begin();
 
        if(!FIND(S, q->first)) {
            S.insert(make_pair(q->first, q->second));
 
            foreach(G[q->first], it) {
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
 
void augment(list< Edge* > *P) {
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
            e->c -= b;
            e->pair->flow -= b;
            e->pair->c += b;
        }
    }
}
 
int max_flow(vector< vector< Edge* > >& G, int src, int sink)
{
    list< Edge * > *P;
    int flow = 0;
 
    while (P = BFS(G, src, sink))
    {
        augment(P);
    }
 
    for (auto e : G[src])
    {
        flow += e->flow;
    }
 
    return flow;
}
 
int main() {
    int T;
 
    scanf("%d\n", &T);
    while (T--) {
        int N, M;
        string s_1, s_2;
        Graph G;
        map< string, int > size_map = { { "XXL", 0 }, { "XL", 1 }, { "L", 2 }, { "M", 3 }, { "S", 4 }, { "XS", 5 } };
        int src, sink;
         
        scanf("%d %d\n", &N, &M);
         
        G.adj.resize(6 + M + 2);
        src = 6 + M;
        sink = 6 + M + 1;
        for (int i = 0; i < 6; ++i)
        {
            G.Insert(src, i, N / 6);
        }
 
        for (int i = 0; i < M; ++i)
        {
            G.Insert(6 + i, sink, 1);
        }
 
        for (int i = 0; i < M; ++i)
        {
            cin >> s_1 >> s_2;
            G.Insert(size_map[s_1], 6 + i, 1);
            G.Insert(size_map[s_2], 6 + i, 1);
        }
 
        cout << (max_flow(G.adj, src, sink) == M ? "YES" : "NO") << endl;
    }
}