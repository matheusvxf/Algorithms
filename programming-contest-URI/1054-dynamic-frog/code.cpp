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
#define INF (int) 1e10

int main()
{
    int T, i = 1;

    scanf("%d\n", &T);
    while (T--)
    {
        int S, D, maximum = 0;
        vector< int > Q;

        scanf("%d %d\n", &S, &D);

        Q.push_back(0);
        while (S--)
        {
            int x;
            char c;
            scanf("%c-%d\n", &c, &x);

            Q.push_back(x);
            if (c == 'B')
                Q.push_back(x);
        }

        Q.push_back(D);
        for (int i = 2; i < Q.size(); ++i)
            maximum = max(maximum, Q[i] - Q[i - 2]);

        printf("Case %d: %d\n", i++, maximum);
    }
}
