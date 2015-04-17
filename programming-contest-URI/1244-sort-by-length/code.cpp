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
    bool operator()(const string& a, const string& b) const
    {
        return a.size() > b.size();
    }
} S;

int main() {
    int T;

    scanf("%d\n", &T);
    while (T--)
    {
        string str;
        stringstream buffer;
        vector< string > Q;

        getline(cin, str);
        buffer.str(str);

        while (buffer >> str)
        {
            Q.push_back(str);
        }

        stable_sort(all(Q), S);

        auto it = Q.begin();
        printf("%s", it->c_str());
        for(++it; it != Q.end(); ++it)
            printf(" %s", it->c_str());
        printf("\n");
    }
}
