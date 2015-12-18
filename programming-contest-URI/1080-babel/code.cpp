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
    int x, y, cost;
    char restriction;

    Edge() : Edge(0, 0) {}
    Edge(int x, int y) : Edge(x, y, 1) {}
    Edge(int x, int y, int cost) : Edge(x, y, cost, 'a') {}
    Edge(int x, int y, int cost, char restriction) : x(x), y(y), cost(cost), restriction(restriction) {}
};

class Graph
{
public:
    vector< vector< Edge* > > adj;

    void Insert(int x, int y, string& word)
    {
        int index = word[0] - 'a';
        int size = word.size();

        for (int j = 0; j < 26; ++j)
        {
            if (j != index)
                adj[x * 26 + index].push_back(new Edge(x * 26 + index, y * 26 + j, size));
        }


        for (int j = 0; j < 26; ++j)
        {
            if (j != index)
                adj[y * 26 + index].push_back(new Edge(y * 26 + index, x * 26 + j, size));
        }
    }
};


class Node
{
public:
    int id;
    int dst;

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

int Dijkstra(Graph G, int src, int dst)
{
    int num_nodes = G.adj.size();
    vector< int > distance(num_nodes);
    set< Node > Q;

    fill(all(distance), INF);

    for (int i = 0; i < 26; ++i)
    {
        Q.insert(Node(src * 26 + i, 0));
        distance[src * 26 + i] = 0;
    }

    for (int i = 0; i < num_nodes; ++i)
    if (i / 26 != src)
        Q.insert(Node(i, INF));

    while (1)
    {
        auto it = Q.begin();
        Node node = *it;

        Q.erase(it);
        if (node.id / 26 == dst)
            return node.dst;
        if (node.dst == INF)
            return INF;

        for (int i = 0, size = G.adj[node.id].size(); i < size; ++i)
        {
            Edge *e = G.adj[node.id][i];
            auto it = Q.find(Node(e->y, distance[e->y]));

            if (it != Q.end() && node.dst + e->cost < it->dst)
            {
                distance[e->y] = node.dst + e->cost;
                Q.erase(it);
                Q.insert(Node(e->y, distance[e->y]));
            }
        }
    }
}

class Dictionary
{
public:
    static int index_counter;

    static void InsertLanguage(unordered_map< string, int >& Language, string lang)
    {
        if (!FIND(Language, lang))
        {
            Language.insert(make_pair(lang, index_counter++));
        }
    }
};

int Dictionary::index_counter = 0;

int main()
{
    int M;

    while (scanf("%d\n", &M) && M != 0)
    {
        string str_src, str_dst;
        unordered_map< string, int > Language;
        Graph G;
        Dictionary::index_counter = 0;

        cin >> str_src >> str_dst;
        Dictionary::InsertLanguage(Language, str_src);
        Dictionary::InsertLanguage(Language, str_dst);
        for (int i = 0; i < M; ++i)
        {
            string a, b, word;
            cin >> a >> b >> word;
            Dictionary::InsertLanguage(Language, a);
            Dictionary::InsertLanguage(Language, b);
            G.adj.resize(Language.size() * 26);
            G.Insert(Language[a], Language[b], word);
        }

        int res = Dijkstra(G, Language[str_src], Language[str_dst]);
        if (res == INF)
            printf("impossivel\n");
        else
            printf("%d\n", res);
    }
}