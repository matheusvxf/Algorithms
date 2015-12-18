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

int main() {
    int N, M;

    while (scanf("%d %d\n", &N, &M) != EOF)
    {
        bool some_peak = false;
        int **m = new int*[N];

        for (int i = 0; i < N; ++i)
        {
            m[i] = new int[M];
            for (int j = 0; j < M; ++j)
            {
                int n;
                scanf("%d", &n);
                m[i][j] = n;
            }
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
                int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
                bool peak = true;

                for (int k = 0; k < 8; ++k)
                {
                    int x = i + dy[k], y = j + dx[k];

                    if (x >= 0 && x < N && y >= 0 && y < M)
                    {
                        peak &= m[i][j] > m[x][y];

                        if (!peak)
                            break;
                    }
                }

                if (peak)
                    printf("%d %d\n", i + 1, j + 1);

                some_peak |= peak;
            }
        }

        if (!some_peak)
            printf("-1\n");

        for (int i = 0; i < N; ++i)
        {
            delete[]m[i];
        }
        delete[]m;
        printf("\n");
    }
}
