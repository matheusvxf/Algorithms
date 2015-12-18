#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)
#define all(Q) Q.begin(), Q.end()
#define LOW 0
#define HIGH 1

bool compare(const int a, const int b)
{
    return a > b;
}

int main()
{
    int N;

    scanf("%d\n", &N);

    while (N--)
    {
        vector< int > Q, S;
        int M;

        scanf("%d\n", &M);

        Q.resize(M);
        for (int i = 0; i < M; ++i)
        {
            int P;
            scanf("%d", &P);
            Q[i] = P;;
        }

        S.insert(S.begin(), all(Q));

        sort(all(S), compare);
        int count = 0;
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] != Q[i])
                count++;
        }

        printf("%d\n", S.size() - count);
    }
}
