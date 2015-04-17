#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

#define uint unsigned int
#define FIND(Q, q) (Q.find(q) != Q.end())
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)
#define INF ((int)10e6)
#define all(Q) Q.begin(), Q.end()

class Edge
{
public:
    int s, d;

    Edge(int s, int d) : s(s), d(d) {}

};

class Vertice
{
public:
    int age;

    Vertice() : Vertice(0) {}
    Vertice(int age) : age(age) {}
};

class Graph
{
public:
    vector< vector< Edge* > > adj;
    vector< Vertice > V;
    int size;
    unordered_map< int, int > people_map;

    Graph(int size) : size(size), adj(size), V(size), people_map(size) {
        for (int i = 0; i < size; ++i)
            people_map[i] = i;
    }

    void Insert(int s, int d)
    {
        adj[s].push_back(new Edge(s, d));
    }
    
};

void Swap(Graph& G, int s, int t)
{
    int real_s = G.people_map[s];
    int real_t = G.people_map[t];
    Vertice vert_tmp = G.V[real_s];
    int tmp = G.people_map[s];

    G.V[real_s] = G.V[real_t];
    G.V[real_t] = vert_tmp;
    G.people_map[s] = G.people_map[t];
    G.people_map[t] = tmp;
}

int DFS(Graph& G, int source)
{
    stack< int > S;
    unordered_set< int > Q(G.adj.size());
    int younger = INF;

    if (G.adj[source].size() == 0)
        return -1;
    Q.insert(source);
    foreach(G.adj[source], edge_it)
        S.push((*edge_it)->d);

    while (!S.empty())
    {
        int p = S.top(); S.pop();

        younger = min(younger, G.V[p].age);

        foreach(G.adj[p], edge_it)
        {
            Edge &e = **edge_it;

            if (!FIND(Q, e.d))
            {
                Q.insert(e.d);
                S.push(e.d);
            }
        }
    }

    return younger;
}

int main() {
    int N, M, I;

    while (scanf("%d %d %d\n", &N, &M, &I) != EOF)
    {
        Graph G(N);
        vector< Vertice > &V = G.V;

        for (int i = 0; i < N; ++i)
        {
            int age;
            scanf("%d", &age);
            V[i].age = age;
        }

        for (int i = 0; i < M; ++i)
        {
            int x, y;
            scanf("%d %d\n", &x, &y); x--; y--;
            G.Insert(y, x);
        }

        for (int i = 0; i < I; ++i)
        {
            char op;
            int x, y;

            scanf("%c", &op);

            if (op == 'T')
            {
                scanf("%d %d\n", &x, &y); x--; y--;
                Swap(G, x, y);
            }
            else
            {
                scanf("%d\n", &x); x--;

                int res = DFS(G, G.people_map[x]);
                if (res == -1)
                    printf("*\n");
                else
                    printf("%d\n", res);
            }
        }
    }
}
