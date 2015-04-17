#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

#define all(Q) Q.begin(), Q.end()

void PrintSolution(vector< vector< bool > >& m, int N, int I, int M)
{
    vector< int > solution;
    int i = 0;
    int y = I;

    while (i < N)
    {
        if (y == M)
        {
            solution.push_back(i);
            i++;
            y = 1;
        }
        else
        {
            if (m[i][y])
            {
                solution.push_back(i);
                i++;
                y = 1;
            }
            else
            {
                i++;
                y++;
            }
        }
    }

    int size = solution.size();
    for (int i = 0; i < size - 1; ++i)
        printf("%d ", solution[i] + 1);
    if (size > 0)
        printf("%d\n", solution[size - 1] + 1);
    else
        printf("%d\n", 0);
}

void DynamicVodka(int N, int I, int M, vector< int >& C, vector< int >& S)
{
    vector< vector< int > > m(N);
    vector< vector< bool > > track(N);

    for (int i = 0; i < N; ++i)
    {
        m[i].resize(M + 1);
        track[i].resize(M + 1);
        fill(all(track[i]), false);
    }

    for (int i = 0; i < M; ++i)
    {
        m[N - 1][i] = min(C[i], S[i]);
        if (m[N - 1][i] == S[i])
            track[N - 1][i] = true;
    }
    m[N - 1][M] = S[M];
    track[N - 1][M] = true;

    for (int i = N - 2; i >= 0; --i)
    {
        m[i][M] = m[i + 1][1] + S[M];
        track[i][M] = true;
        for (int j = M - 1; j >= 0; --j)
        {
            m[i][j] = min(m[i + 1][1] + S[j], m[i + 1][j + 1] + C[j]);
            if (m[i][j] == m[i + 1][1] + S[j])
                track[i][j] = true;
        }
    }

    printf("%d\n", m[0][I]);

    PrintSolution(track, N, I, M);
}

int main() {
    int N, I, M, P;

    while (scanf("%d %d %d %d\n", &N, &I, &M, &P) != EOF)
    {
        vector< int > C(M);
        vector< int > S(M + 1);

        for (int i = 0; i < M; ++i)
        {
            int tmp;
            scanf("%d", &tmp);
            C[i] = tmp;
        }

        S[0] = C[0];
        for (int i = 1; i <= M; ++i)
        {
            int tmp;
            scanf("%d", &tmp);
            S[i] = P - tmp + C[0];
        }

        DynamicVodka(N, I, M, C, S);
    }
}
