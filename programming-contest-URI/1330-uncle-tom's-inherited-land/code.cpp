#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cassert>
#include <string.h>
#include <stdio.h>
 
using namespace std;
 
#define uint unsigned int
#define INF 10e6
#define FIND(Q, q) (Q.find(q) != Q.end())
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)
#define all(Q) Q.begin(), Q.end()

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

class Node
{
public:
    enum Type
    {
        POUND = 1,
        NORMAL = 0
    };

    enum Color
    {
        BLUE = 2,
        RED = 1,
        NONE = 0
    };

    Type type;
    Color color;

    Node() : type(NORMAL), color(NONE) {}
};

class Graph
{
public:
    vector< vector< Edge* > > adj;
    vector< Node > V;

    void Insert(int x, int y)
    {
        adj[x].push_back(new Edge(x, y));
    }

    void Insert(int x, int y, int c)
    {
        adj[x].push_back(new Edge(x, y, c, Edge::forward));
        adj[y].push_back(new Edge(y, x, 0, Edge::backward));
        adj[x].back()->pair = adj[y].back();
        adj[y].back()->pair = adj[x].back();
    }

    void clear()
    {
        foreach(adj, adj_it)
        {
            foreach(*adj_it, edge_it)
            {
                delete *edge_it;
            }
        }
    }
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
 
inline bool IsEven(int i)
{
    return i % 2 == 0;
}

inline void test_gen();

int main()
{
    int N, M;
 
    //test_gen();
    //exit;

    while (scanf("%d %d\n", &N, &M) && N != 0)
    {
        int K, s_index, t_index;
        vector< pair< int, int > > node;
        vector< int > A, B;
        Graph G;

        s_index = N * M;
        t_index = N * M + 1;
        G.adj.resize(N * M + 2);
        G.V.resize(N * M + 2);

        scanf("%d\n", &K);
        for (int i = 0; i < K; ++i)
        {
            int x, y;
            scanf("%d %d\n", &x, &y); x--; y--;
            G.V[x * M + y].type = Node::POUND;
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (G.V[i * M + j].type == Node::NORMAL)
                {
                    if ((IsEven(i) && !IsEven(j)) || (!IsEven(i) && IsEven(j)))
                    {
                        G.V[i * M + j].color = Node::RED;
                        G.Insert(s_index, i * M + j, 1);
                    }
                    else
                    {
                        B.push_back(i * M + j);
                        G.V[i * M + j].color = Node::BLUE;
                        G.Insert(i * M + j, t_index, 1);
                    }
                }
            }
        }

        for (int l = 0; l < N; ++l)
        {
            for (int c = 0; c < M; ++c)
            {
                if (G.V[l * M + c].type == Node::NORMAL)
                {
                    int line_inc[] = { -1, 0, 0, 1 };
                    int column_inc[] = { 0, -1, 1, 0 };
                    int color_s = G.V[l * M + c].color;

                    for (int k = 0; k < 4; ++k)
                    {
                        int line = l + line_inc[k], column = c + column_inc[k];

                        if (line >= 0 && line < N && column >= 0 && column < M &&
                            G.V[line * M + column].type == Node::NORMAL)
                        {
                            int color_t = G.V[line * M + column].color;

                            if (color_s != color_t && color_s == Node::RED)
                                G.Insert(l * M + c, line * M + column, 1);
                        }
                    }
                }
            }
        }
 
        printf("%d\n", max_flow(G.adj, s_index, t_index));

        G.clear();
    }
}

void test_gen()
{
    int N_TEST = 10;
    
    fstream stream("test.in", std::fstream::out);
    

    while (N_TEST--)
    {
        int N = rand() % 100 + 1, M = rand() % 100 + 1;
        int K = rand() % (N * M);

        stream << N << " " << M << endl;
        stream << K << endl;
        for (int i = 0; i < K; ++i)
        {
            stream << rand() % N + 1 << " " << rand() % M + 1 << endl;
        }
    }

    stream << 0 << " " << 0 << endl;
}