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
    int K;

    while (scanf("%d", &K) != EOF)
    {
        int N, M;

        scanf("%d %d", &N, &M);

        for (int i = 0; i < K; ++i)
        {
            int x, y, X, Y;

            scanf("%d %d", &X, &Y);

            x = X - N;
            y = Y - M;

            if (x == 0 || y == 0)
                printf("divisa\n");
            else if (x > 0 && y > 0)
                printf("NE\n");
            else if (x < 0 && y > 0)
                printf("NO\n");
            else if (x > 0 && y < 0)
                printf("SE\n");
            else
                printf("SO\n");            
        }
    }
}
