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
#include <string>

using namespace std;

#define uint unsigned int
#define FIND(Q, q) (Q.find(q) != Q.end())
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)
#define INF ((int)10e6)
#define all(Q) Q.begin(), Q.end()

class Sort
{
public:
    bool operator()(const pair< int, int >&a, const pair< int, int >&b) const
    {
        if (a.second < b.second)
            return true;
        else if (a.second > b.second)
            return false;
        else 
            return a.first > b.first;
    }
} S;

int main() {
    char c;
    bool first = true;

    while (scanf("%c", &c) != EOF)
    {
        map< int, int > m;

        if (!first)
        {
            printf("\n");
        }
        first = false;

        m[c]++;
        while (scanf("%c", &c) && c != '\n')
        {
            m[c]++;
        }

        vector< pair< int, int > > Q(all(m));
        sort(all(Q), S);

        foreach(Q, it)
        {
            printf("%d %d\n", it->first, it->second);
        }
    }
}
