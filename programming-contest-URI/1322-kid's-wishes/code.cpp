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
    unordered_map< int, vector< Edge* > > adj;
    unordered_map< int, Vertice* > V;
    unordered_map< int, set< int > > connection;
    int num_nodes;
    static int index;
    static stack< Vertice* > S;
    static set< pair< int, int > > E;

    Graph() {}

    bool Insert(int x, int y)
    {
        int tmp = x;
        x = min(x, y);
        y = max(y, tmp);
        if (!FIND(connection[x], y))
        {
            connection[x].insert(y);
            connection[y].insert(x);
            adj[x].push_back(new Edge(x, y));
            adj[y].push_back(new Edge(y, x));
        }

        return connection[x].size() <= 2 && connection[y].size() <= 2;
    }

    void Insert(int x)
    {
        if (!FIND(V, x))
            V[x] = new Vertice(x);
    }

    bool Tartjan(){
        index = 0;

        foreach(V, it)
        {
            E.clear();
            if (it->second->index == UNDEFINED)
            {
                vector< Vertice * > component = StrongConnect(it->second);

                if (component.size() > 2 && component.size() != num_nodes)
                {
                    return false;
                }
            }
        }

        return true;
    }

    vector< Vertice* > StrongConnect(Vertice* v)
    {
        vector< Vertice* > component;
        v->index = index;
        v->lowlink = index;
        index++;
        S.push(v);

        foreach(adj[v->id], it)
        {
            auto pair = make_pair(min((*it)->x, (*it)->y), max((*it)->x, (*it)->y));
            if (!FIND(E, pair))
            {
                Vertice *w = V[(*it)->y];
                
                E.insert(pair);
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

        return component;
    }

};

int Graph::index = 0;
stack< Vertice* > Graph::S;
set< pair< int, int > > Graph::E;

bool Solve(Graph& G)
{
    return G.Tartjan();
}

int main() {
	uint K, W, x, y;

    while (cin >> K >> W && (K != 0 || W != 0)) {
        Graph G;
        bool feasible = true;
        
		for(register uint j = 0; j < W; ++j) {
            cin >> x >> y;
            G.num_nodes = K;
            G.Insert(x); G.Insert(y);
            feasible &= G.Insert(x, y);
		}

        cout << (feasible && Solve(G) ? "Y" : "N") << endl;
	}
}
