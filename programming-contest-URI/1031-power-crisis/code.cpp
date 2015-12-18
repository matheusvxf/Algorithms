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
    int N;

    while (scanf("%d", &N) && N != 0)
    {
        int *lbl = new int[N];
        int m = 1;

        while (1)
        {
            int i = 0, k = 0;

            memset(lbl, 0, sizeof(lbl[0]) * N);

            while (i < N)
            {
                int counter = 0;

                lbl[k]++;
                i++;

                if (k == 12)
                    break;

                while (counter < m)
                {
                    k = (k + 1) % N;
                    if (lbl[k] == 0)
                        counter++;
                }
            }

            if (k == 12 && i == N)
                break;
            m++;
        }

        printf("%d\n", m);
        delete[]lbl;
    }
}
