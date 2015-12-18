#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>
#include <string>
#include <string.h>

using namespace std;

#define uint unsigned int
#define FIND(Q, q) (Q.find(q) != Q.end())
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)

class Edge;

class Graph
{
public:
    vector< set< Edge*, Edge > > adj;
    void Insert(int x, int y);
    void clear();
};

class Node
{
public:
    Node *left, *right;
    int key;
    int data;
    static int counter;
    static Graph graph;
    static vector< Node* > Pool;

    Node(int data) : Node(data, nullptr) {}
    Node(int data, Node *parent) : data(data), key(counter++), left(nullptr), right(nullptr)
    {
        if (key >= 0)
            Pool.push_back(this);
        if (parent && parent->key >= 0)
            graph.Insert(parent->key, key);
    }

    void Insert(int data)
    {
        if (data < this->data)
        {
            if (left)
                left->Insert(data);
            else
                left = new Node(data, this);
        }
        else
        {
            if (right)
                right->Insert(data);
            else
                right = new Node(data, this);
        }
    }

    static void CollectMemory()
    {
        foreach(Pool, it) delete *it;
        Pool.clear();
    }

    static void clear()
    {
        Node::CollectMemory();
        Node::counter = -1;
        Node::graph.clear();
    }
};

class Edge
{
public:
    uint x, y, c;
    static vector< Edge * > Pool;

    Edge() : Edge(-1, -1) {}
    Edge(uint x, uint y) : Edge(x, y, 0) {}
    Edge(uint x, uint y, uint c) : x(x), y(y), c(c) {}

    bool operator<(const Edge* b) const
    {
        return Node::Pool[this->y]->data < Node::Pool[b->y]->data;
    }
    bool operator()(const Edge* a, const Edge* b) const
    {
        return Node::Pool[a->y]->data < Node::Pool[b->y]->data;
    }

    static void clear()
    {

    }
};

vector< Edge* > Edge::Pool;

void Graph::Insert(int x, int y)
{
    adj[x].insert(new Edge(x, y));
}

void Graph::clear()
{
    adj.clear();
    Edge::clear();
}

int Node::counter = -1;
vector< Node * > Node::Pool;
Graph Node::graph;

class Tree{
public:
    Node *root;

    Tree()
    {
        root = new Node(-1);
    }

    void Insert(int data)
    {
        root->Insert(data);
    }
};

int BFS(const vector< set< Edge*, Edge > >& G, int src) {
    deque< int > Q;
    int *lbl = new int[G.size()];
    memset(lbl, 0, sizeof(int)* G.size());

	Q.push_back(src);
    printf("%d", Node::Pool[src]->data);

	while(!Q.empty()) {
        auto q = Q.front();
        Q.pop_front();
        
        foreach(G[q], neighbor)
        {
            Edge *e = *neighbor;
            if (lbl[e->y] == 0)
            {
                if (e->y != src)
                    printf(" %d", Node::Pool[e->y]->data);
                lbl[e->y]++;
                Q.push_back(e->y);
            }
        }
	}
    printf("\n\n");

	return -1;
}

int main() {
    int C;

    scanf("%d", &C);

    for (int j = 1; j <= C; ++j)
    {
        int N;
        Tree T;

        scanf("%d", &N);
        Node::graph.adj.resize(N);

        for (int i = 0; i < N; ++i)
        {
            int tmp;

            scanf("%d", &tmp);
            T.Insert(tmp);
        }

        printf("Case %d:\n", j);
        BFS(Node::graph.adj, 0);

        Node::clear();
    }
}
