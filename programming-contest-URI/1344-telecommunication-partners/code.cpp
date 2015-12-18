#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <unordered_map>

using namespace std;

#define uint64 unsigned long long int
#define DEBUG 0
#define FIND(Q, a) (Q.find(a) != Q.end())

class Edge
{
public:
    int s, d;

    Edge(int s, int d) : s(s), d(d) {}
};

class Graph
{
public:

    vector< vector< Edge* > > adj;
    int size;

    Graph(int size) : size(size), adj(size) {}

    void Insert(int x, int y)
    {
        adj[x].push_back(new Edge(x, y));
        adj[y].push_back(new Edge(y, x));
    }
};

int main() {
    int N, P, K;

    while (scanf("%d %d %d\n", &N, &P, &K) && N != 0)
    {
        unordered_map< int, int > counter;
        Graph G(N);
        int acumulator = 0;

        for (int i = 0; i < P; ++i)
        {
            int x, y;
            scanf("%d %d\n", &x, &y);
            G.Insert(x, y);
        }

    }
}
