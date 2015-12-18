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
        adj.resize(max(max((int)adj.size(), (x + 1) * 26), (y + 1) * 26));
        for (int i = 0; i < 26; ++i)
        {
            adj[x * 26 + i].push_back(new Edge(x, y, word.size(), word[0]));
            adj[y].push_back(new Edge(y, x, word.size(), word[0]));
        }
    }
};

int Dictionary::index_counter = 0;

class Node
{
public:
    int id;
    int dst;
    char restriction;

    Node() : Node(0) {}
    Node(int id) : Node(id, 0) {}
    Node(int id, int dst) : Node(id, dst, 0) {}
    Node(int id, int dst, char restriction) : id(id), dst(dst), restriction(restriction) {}

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
    Q.insert(Node(src, 0));
    distance[src] = 0;

    for (int i = 0; i < num_nodes; ++i)
        Q.insert(Node(i, INF));

    while (1)
    {
        auto it = Q.begin();
        Node node = *it;

        Q.erase(it);
        if (node.id == dst)
            return node.dst;
        if (node.dst == INF)
            return INF;

        for(int i = 0, size = G.adj[node.id].size(); i < size; ++i) {
            Edge *e = G.adj[node.id][i];
            auto it = Q.find(Node(e->y, distance[e->y]));

            if (it != Q.end() && node.dst + e->cost < it->dst && e->restriction != node.restriction)
            {
                distance[e->y] = node.dst + e->cost;
                Q.erase(it);
                Q.insert(Node(e->y, distance[e->y], e->restriction));
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
            G.Insert(Language[a], Language[b], word);
        }

        int res = Dijkstra(G, Language[str_src], Language[str_dst]);
        if (res == INF)
            printf("impossivel\n");
        else
            printf("%d\n", res);
    }
}