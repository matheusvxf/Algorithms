#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <set>
#include <unordered_set>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef vector<int> vi;

#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)
#define all(Q) Q.begin(), Q.end()
#define MAX_V 40 // enough for sample graph in Figure 4.24/4.25/4.26/UVa 259
#define INF 1000000000

int res[MAX_V][MAX_V], mf, f, s, t;                          // global variables
vi p;

void augment(int v, int minEdge)
{     // traverse BFS spanning tree from s to t
    if (v == s) { f = minEdge; return; }  // record minEdge in a global variable f
    else if (p[v] != -1)
    {
        augment(p[v], min(minEdge, res[p[v]][v])); // recursive
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }       // update
}
 
int max_flow()
{
    mf = 0;                                              // mf stands for max_flow
    while (1)
    {              // O(VE^2) (actually O(V^3E) Edmonds Karp's algorithm
        f = 0;
        // run BFS, compare with the original BFS shown in Section 4.2.2
        vi dist(MAX_V, INF); dist[s] = 0; queue<int> q; q.push(s);
        p.assign(MAX_V, -1);           // record the BFS spanning tree, from s to t!
        while (!q.empty())
        {
            int u = q.front(); q.pop();
            if (u == t) break;      // immediately stop BFS if we already reach sink t
            for (int v = 0; v < MAX_V; v++)                 // note: this part is slow
            if (res[u][v] > 0 && dist[v] == INF)
                dist[v] = dist[u] + 1, q.push(v), p[v] = u;
        }
        augment(t, INF);     // find the min edge weight `f' along this path, if any
        if (f == 0) break;      // we cannot send any more flow (`f' = 0), terminate
        mf += f;                 // we can still send a flow, increase the max flow!
    }
                      
    // this is the max flow value
    return mf;
}
 
struct problem
{
    char name;
    int users;
    unordered_set< int > computers;

    problem(char name_, int users_, vi computers_)
    {
        name = name_;
        users = users_;
        computers.insert(all(computers_));
    }
};

int main() {
    char name;
    int users;
    char computer;
    string str;

    while (getline(cin, str))
    {
        stringstream buffer(str);
        vector< problem > Q;
        vi computers;
        int goal = 0;
        memset(res, 0, sizeof res);

        buffer >> name >> users >> computer;
        computers.push_back(computer - '0');
        while (buffer >> computer && computer != ';')
            computers.push_back(computer - '0');
        Q.push_back(problem(name, users, computers));

        while (getline(cin, str) && !str.empty())
        {
            stringstream buffer(str);
            vi computers;
            buffer >> name >> users >> computer;
            computers.push_back(computer - '0');
            while (buffer >> computer && computer != ';')
                computers.push_back(computer - '0');
            Q.push_back(problem(name, users, computers));
        }

        s = 0;
        int num_problems = 26;
        int comp_offset = 1 + num_problems;
        t = comp_offset + 10;
        for (auto &p : Q)
        {
            int prob = p.name - 'A' + 1;
            res[s][prob] = p.users;
            goal += p.users;
            for (auto &c : p.computers)
            {
                res[prob][c + comp_offset] = 1;
            }
        }

        for (int i = 0; i < 10; ++i)
        {
            res[i + comp_offset][t] = 1;
        }

        max_flow();
        if (mf != goal){
            printf("!\n");
        }
        else
        {
            for (int i = 0; i < 10; ++i)
            {
                bool assigned = false;
                for (auto &p : Q) {
                    int index = p.name - 'A' + 1;

                    if (res[i + comp_offset][index] != 0)
                    {
                        printf("%c", p.name);
                        assigned = true;
                        break;
                    }
                }
                
                if (!assigned)
                    printf("_");
            }
            printf("\n");
        }
    }
}