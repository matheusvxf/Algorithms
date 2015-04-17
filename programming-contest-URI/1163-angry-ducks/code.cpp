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
#define pi 3.14159

int main() {
    double h;

    while (scanf("%lf\n", &h) != EOF)
    {
        int p1, p2, n;
        double a, v, ay = -9.80665, vy, vx, cy, t, x;

        scanf("%d %d\n", &p1, &p2);
        scanf("%d\n", &n);

        for (int i = 0; i < n; ++i)
        {
            scanf("%lf %lf", &a, &v);

            a = a * 2.0 * pi / 360.0;
            vy = v * sin(a);
            vx = v * cos(a);
            cy = h;
            t = (-vy - sqrt(vy * vy - 2 * ay * cy)) / (ay);
            t = max(t, (-vy + sqrt(vy * vy - 2 * ay * cy)) / (ay));
            x = vx * t;

            printf("%.5lf -> %s\n", x, (x >= p1 && x <= p2 ? "DUCK" : "NUCK"));
        }
    }
}
