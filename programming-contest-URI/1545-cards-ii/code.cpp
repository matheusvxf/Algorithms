#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cassert>
#include <unordered_map>
#include <string.h>
#include <stdio.h>
 
using namespace std;
 
#define uint unsigned int
#define INF 1e15
#define FIND(Q, q) (Q.find(q) != Q.end())
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)
#define all(Q) Q.begin(), Q.end()

class Solve
{
public:
    vector< int > v;
    int N;

    Solve()
    {
    }
    
    long long int OPT()
    {
        vector< long long int > m(N);
        vector< long long int > prev(N);
        vector< long long int > sum(N + 1);

        sum[N] = 0;
        for (int i = N - 1; i >= 0; --i)
        {
            sum[i] = sum[i + 1] + v[i];
        }

        for (int i = 0; i < N; ++i)
            prev[i] = 0;

        for (int l = 2; l <= N; ++l)
        {
            for (int i = 0; i <= N - l; ++i)
            {
                int j = i + l - 1;
                if (l % 2 != 0)
                    m[i] = max(prev[i + 1], prev[i]);
                else
                    m[i] = max(prev[i + 1] + v[i], prev[i] + v[j]);
            }

            prev = m;
        }

        return m[0];
    }

    void Set(int N)
    {
        this->N = N;
        v.resize(N);
    }
} S;

int main()
{
    int N;

    while (scanf("%d\n", &N) != EOF)
    {
        S.Set(N);
        vector< int > &v = S.v;

        for (int i = 0; i < N; ++i)
            scanf("%d", &v[i]);

        printf("%lld\n", S.OPT());
    }
}
