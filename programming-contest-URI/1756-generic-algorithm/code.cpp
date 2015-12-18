#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <stdio.h>

using namespace std;

#define all(Q) Q.begin(), Q.end()
#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)
#define INF (int)1e10

int main() {
    int T;

    scanf("%d\n", &T);
    while (T--)
    {
        int N, Y;
        double p, P, acumulator;
        char x[9], y[9], z[9], a[9], b[9];

        scanf("%d\n", &N);
        scanf("%d %lf\n", &Y, &p);
        scanf("%s\n", &x);
        scanf("%s\n", &y);
        scanf("%s\n", &z);

        for (int i = 0; i < Y; ++i)
        {
            a[i] = x[i];
            b[i] = y[i];
        }
        for (int i = Y; i < N; ++i)
        {
            a[i] = y[i];
            b[i] = x[i];
        }

        P = 1.0;
        for (int i = 0; i < N; ++i)
        {
            if (a[i] == z[i])
                P *= (1.0 - p);
            else
                P *= p;
        }
        acumulator = P;
        P = 1.0;
        for (int i = 0; i < N; ++i)
        {
            if (b[i] == z[i])
                P *= (1.0 - p);
            else
                P *= p;
        }
        acumulator = 1.0 - (1.0 - acumulator) * (1.0 - P) ;

        printf("%.7lf\n", acumulator);
    }
}
