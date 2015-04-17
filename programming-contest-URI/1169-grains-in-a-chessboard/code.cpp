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
        int X;
        unsigned long long int grains = 0, grams, prev;

        scanf("%d\n", &X);

        prev = 1, grams = 0;
        grains = prev;
        for (int i = 1; i < X; ++i)
        {
            prev = prev * 2;
            grains += prev;
            grams += grains / 12;
            grains = grains % 12;
        }

        printf("%llu kg\n", grams / 1000);

    }
}
