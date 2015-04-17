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
#define GET(x, y) scanf("%d %d\n", &x, &y)
#define GET1(x) scanf("%d", &x)

int DynamicCandy(int **C, int N, int M)
{
    int max_x = M;
    int max_y = N;
    int ***m = new int**[max_y];

    for (int i = 0; i < max_y; ++i)
    {
        m[i] = new int*[max_x];
        for (int j = 0; j < max_x; ++j)
            m[i][j] = new int[2];
    }

    for (int j = max_x - 1, i = max_y - 1; j >= 0; --j)
    {
        if (j + 2 < max_x)
            m[i][j][0] = m[max_y - 1][j][1] = max(m[i][j + 2][0] + C[i][j], m[i][j + 1][0]);
        else if (j + 1 < max_x)
            m[i][j][0] = m[max_y - 1][j][1] = max(C[i][j], m[i][j + 1][0]);
        else
            m[i][j][0] = m[max_y - 1][j][1] = C[i][j];
    }


    for (int i = max_y - 2; i >= 0; --i)
    {
        for (int j = max_x - 1; j >= 0; --j)
        {
            if (j + 1 == max_x)
            {
                if (i + 2 == max_y)
                {
                    m[i][j][0] = max(C[i][j], m[i + 1][0][0]);
                    m[i][j][1] = C[i][j];
                }
                else
                {
                    m[i][j][0] = max(m[i + 2][0][0] + C[i][j], m[i + 1][0][0]);
                    m[i][j][1] = m[i + 2][0][0] + C[i][j];
                }
            }
            else if (j + 2 == max_x)
            {
                if (i + 2 == max_y)
                {
                    m[i][j][0] = max(C[i][j], m[i][j + 1][0]);
                    m[i][j][1] = max(C[i][j], m[i][j + 1][1]);
                }
                else
                {
                    m[i][j][0] = max(m[i + 2][0][0] + C[i][j], m[i][j + 1][0]);
                    m[i][j][1] = max(m[i + 2][0][0] + C[i][j], m[i][j + 1][1]);
                }
            }
            else
            {
                m[i][j][0] = max(m[i][j + 2][1] + C[i][j], m[i][j + 1][0]);
                m[i][j][1] = max(m[i][j + 2][1] + C[i][j], m[i][j + 1][1]);
            }
        }
    }

    return m[0][0][0];
}

int main()
{
    int N, M;

    while (GET(N, M) && N != 0)
    {
        int **C = new int*[N];

        for (int i = 0; i < N; ++i)
        {
            C[i] = new int[M];

            for (int j = 0; j < M; ++j)
            {
                int n;
                GET1(n);
                C[i][j] = n;
            }
        }

        printf("%d\n", DynamicCandy(C, N, M));
    }
}
