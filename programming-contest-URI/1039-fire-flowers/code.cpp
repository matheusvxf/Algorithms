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

int main() {
    int r1, x1, y1, r2, x2, y2;

    while (scanf("%d %d %d %d %d %d\n", &r1, &x1, &y1, &r2, &x2, &y2) != EOF)
    {
        printf("%s\n", (r1 >= r2) && (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= (r1 - r2) * (r1 - r2) ? "RICO" : "MORTO");
    }
}
