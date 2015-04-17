#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <stdio.h>

using namespace std;

#define all(Q) Q.begin(), Q.end()

int main() {
    int n, m;

    while (scanf("%d %d", &n, &m) != EOF)
    {
        unordered_map< int, vector< int > > Q;

        for (int i = 1; i <= n; ++i)
        {
            int num;
            scanf("%d", &num);
            Q[num].push_back(i);
        }

        for (int i = 0; i < m; ++i)
        {
            int k, v;

            scanf("%d %d\n", &k, &v);
            auto it = Q.find(v);

            if (it != Q.end())
            {
                if (k <= it->second.size())
                    printf("%d\n", it->second[k - 1]);
                else
                    printf("0\n");
            }
            else
                printf("0\n");
        }
    }
}
