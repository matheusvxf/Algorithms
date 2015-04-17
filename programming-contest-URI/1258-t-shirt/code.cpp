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

class T_shirt
{
public:
    string name, color, size;

    T_shirt(string &name, string &color, string &size) : name(name), color(color), size(size) {}

    bool operator<(const T_shirt& a) const
    {
        if (color < a.color)
            return true;
        else if (color > a.color)
            return false;
        else if (size > a.size)
            return true;
        else if (size < a.size)
            return false;
        else
            return name < a.name;
    }
};

int main() {
    int N;
    bool first = true;

    while (scanf("%d\n", &N) && N != 0)
    {
        string name, color, size;
        vector< T_shirt > Q;

        if (!first)
            printf("\n");
        first = false;

        for (int i = 0; i < N; ++i)
        {
            getline(cin, name);
            cin >> color >> size;
            Q.push_back(T_shirt(name, color, size));
            getline(cin, name);
        }

        sort(all(Q));

        for (int i = 0; i < N; ++i)
        {
            printf("%s %s %s\n", Q[i].color.c_str(), Q[i].size.c_str(), Q[i].name.c_str());
        }
    }
}
