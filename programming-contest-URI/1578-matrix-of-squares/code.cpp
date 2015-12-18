#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

#define all(Q) Q.begin(), Q.end()

int CountDigits(unsigned long long int num)
{
    unsigned long long int base = 1;
    int digits = 0;

    if (num >= (unsigned long long int)1e19)
        return 20;

    while (num / base != 0) {
        base *= 10;
        digits++;
    }

    return digits;
}

int main() {
    int N;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int M;
        vector< vector< unsigned long long int > > Q;
        vector< unsigned long long int > max;
        vector< int > digites;
        printf("Quadrado da matriz #%d:\n", i + 4);
        cin >> M;
        Q.resize(M);
        max.resize(M);
        digites.resize(M);
        fill(all(max), 0);

        for (int j = 0; j < M; ++j)
        {
            Q[j].resize(M);
            for (int k = 0; k < M; ++k)
            {
                unsigned long long int num;
                cin >> num;
                num *= num;
                max[k] = std::max(num, max[k]);
                Q[j][k] = num;
            }
        }

        for (int k = 0; k < M; ++k)
            digites[k] = CountDigits(max[k]);

        for (int j = 0; j < M; ++j)
        {
            for (int k = 0; k < M - 1; ++k)
                printf("%*llu ", digites[k], Q[j][k]);
            printf("%*llu\n", digites[M - 1], Q[j][M - 1]);
        }

        if (i < N - 1)
            printf("\n");
    }
}
