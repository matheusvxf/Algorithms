#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <stack>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <stdio.h>

using namespace std;

#define uint unsigned int
#define INF ((int)10e6)
#define FIND(Q, q) (Q.find(q) != Q.end())
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)

#define UNDEFINED -1

class Vertice
{
public:
    int id, index, lowlink;

    Vertice() : Vertice(0) {}
    Vertice(int id) : id(id), index(UNDEFINED), lowlink(0) {}
};

class Edge
{
public:
    int x, y;

    Edge(int x, int y) : x(x), y(y) {}
};

class Graph
{
public:
    vector< vector< Edge* > > adj;
    vector< Vertice* > V;
    int num_nodes;
    static int index;
    static stack< Vertice* > S;

    Graph() {}

    Graph(int size) : adj(size), num_nodes(size), V(size) {
        for (int i = 0; i < size; ++i)
            V[i] = new Vertice(i);
    }

    void Insert(int x, int y)
    {
        adj[x].push_back(new Edge(x, y));
    }

    bool Tartjan()
    {
        index = 0;

        foreach(V, it)
        {
            Vertice &v = **it;

            if (v.index == UNDEFINED)
            {
                vector< Vertice *> &component = *StrongConnect(&v);
                bool result = component.size() == num_nodes;

                delete &component;
                return result;
            }
        }

        return true;
    }

    vector< Vertice* >* StrongConnect(Vertice* v)
    {
        vector< Vertice* > &component = *new vector< Vertice* >;
        v->index = index;
        v->lowlink = index;
        index++;
        S.push(v);

        foreach(adj[v->id], it)
        {
            Vertice *w = V[(*it)->y];

            if (w->index == UNDEFINED)
            {
                StrongConnect(w);
                v->lowlink = min(v->lowlink, w->lowlink);
            }
            else
            {
                v->lowlink = min(v->lowlink, w->lowlink);
            }
        }

        if (v->lowlink == v->index)
        {
            Vertice *w;
            do
            {
                w = S.top(); S.pop();
                component.push_back(w);
            } while (!(w == v));
        }

        return &component;
    }

};

int Graph::index = 0;
stack< Vertice* > Graph::S;

int main()
{
    int N, M;

    while (scanf("%d %d\n", &N, &M) && N != 0)
    {
        Graph G(N);

        for (int i = 0; i < M; ++i)
        {
            int V, W, P;
            scanf("%d %d %d\n", &V, &W, &P); V--; W--;

            if (P == 1)
            {
                G.Insert(V, W);
            }
            else
            {
                G.Insert(V, W);
                G.Insert(W, V);
            }
        }

        printf("%d\n", G.Tartjan() ? 1 : 0);
    }
}