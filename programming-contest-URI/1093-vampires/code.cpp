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
    int EV1, EV2, AT, D;

    while (scanf("%d %d %d %d\n", &EV1, &EV2, &AT, &D) && EV1 != 0)
    {
        int n1 = EV1 / D + (EV1 % D ? 1 : 0);
        int n2 = EV2 / D + (EV2 % D ? 1 : 0);
        double p = (double)AT / 6.0;
        double q = 1.0 - p;
        double a = q / p;
        double P;
        
        if (AT == 3)
            P = (double)n1 / (double)(n1 + n2);
        else
            P = 1.0 - (pow(a, (double)n1) - pow(a, (double)(n1 + n2))) / (1 - pow(a, (double)(n1 + n2)));
        
        printf("%.1lf\n", P * 100);
    }
}
