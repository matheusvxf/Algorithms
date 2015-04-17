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
        int N, I;
        double p;

        scanf("%d %lf %d\n", &N, &p, &I);
        if (p > 0.0)
            printf("%.4lf\n", pow(1.0 - p, (double)I - 1.0) * p / (1.0 - pow(1.0 - p, (double)N)));
        else
            printf("%.4lf\n", 0.0);
    }
}
