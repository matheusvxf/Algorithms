#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <sstream>
#include <stack>
#include <list>
#include <array>
#include <queue>
#include <unordered_map>
#include <string.h>

using namespace std;

#define INF (1 << 30)
#define all(Q) Q.begin(), Q.end()

int Solve(vector< int >& Q, int n)
{
    int s[100][100] = { 0 };
    int m[100][11] = { 0 };
    int N = Q.size();
    int T = n + 1;

    for (int i = 0; i < N; ++i)
    {
        s[i][i] = Q[i];
        for (int j = i + 1; j < N; ++j)
            s[i][j] = s[i][j-1] + Q[j];
    }

    for (int i = 0; i < N; ++i)
        m[i][0] = INF;
    for (int i = 1; i < T; ++i)
        m[N - 1][i] = Q[N - 1];

    for (int i = N - 2; i >= 0; i--)
    {
        for (int t = 1; t < T; ++t)
        {
            int minimum = INF;
            for (int j = i; j < N; ++j)
            {
                minimum = min(minimum, max(s[i][j], m[j + 1][t - 1]));
            }
            m[i][t] = minimum;
        }
    }

    return m[0][n];
}

int main(){
    int T;

    scanf("%d\n", &T);
    while(T--) {
        int nPainels, trucks, freight;
        vector< int > Q;

        scanf("%d %d %d\n", &nPainels, &trucks, &freight);

        for (int i = 0; i < nPainels; ++i)
        {
            int num;
            scanf("%d", &num);
            Q.push_back(num);
        }

        int maximum = Solve(Q, trucks);

        printf("%d $%d\n", maximum, maximum * freight * trucks);
    }
}
