#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

#define all(S) S.begin(), S.end()
#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)

bool SubSetSum(vector< int > Q, int target)
{
    vector< bool > m;
    int maximum = 0;
    
    foreach(Q, it) maximum += *it;
    m.resize(maximum + 1);
    fill(all(m), false);
    m[0] = true;

    for (int i = 0, size = Q.size(); i < size; ++i)
    {
        for (int j = maximum; j >= Q[i]; --j)
        {
            m[j] = m[j] | m[j - Q[i]];
        }
    }

    return m[target];
}

int main() {
    int R, K;

    while (scanf("%d %d", &R, &K) != EOF)
    {
        vector< int > Q(R);
        int value, total = K;

        for (int i = 0; i < K; ++i)
        {
            int x, y;

            scanf("%d %d", &x, &y);
            x--; y--;

            Q[x]++;
            Q[y]++;
        }
        
        sort(all(Q));
       

        printf("%s\n", SubSetSum(Q, K) ? "S" : "N");
	}
}
