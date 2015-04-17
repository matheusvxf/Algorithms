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
    float x, y;

    while (cin >> x >> y)
    {
        if (x == 0 && y == 0)
            printf("Origem\n");
        else if (x == 0)
            printf("Eixo Y\n");
        else if (y == 0)
            printf("Eixo X\n");
        else if (x > 0 && y > 0)
            printf("Q1\n");
        else if (x < 0 && y > 0)
            printf("Q2\n");
        else if (x < 0 && y < 0)
            printf("Q3\n");
        else
            printf("Q4\n");
    }
}
