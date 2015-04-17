#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <stdio.h>

using namespace std;

#define all(Q) Q.begin(), Q.end()
#define INF (int) 1e10

int BinarySearch(vector< int >& V, int n)
{
    int lower_bound = 0, upper_bound = V.size() - 1;

    while (lower_bound <= upper_bound)
    {
        int avr = (lower_bound + upper_bound) / 2;

        if (V[avr] == n)
            return avr;

        if (lower_bound == upper_bound && V[avr] >= n)
            return avr;

        if (V[avr] < n)
        {
            lower_bound = avr + 1;
        }
        else
        {
            upper_bound = avr;
        }
    }

    return lower_bound;
}

int MinimizeSwaps(vector< int >& V, int k)
{
    int minimum = INF, acumulator = 0, diff, i_atual, swaps, next_i, max;

    for (int i = 0, N = V.size(); i < N; ++i)
    {
        max = V[i] + k - 1;
        next_i = BinarySearch(V, max);

        if (next_i >= N)
            next_i--;
        else if (V[next_i] > max)
            next_i--;

        swaps = (k - 1) - (next_i - i);

        minimum = min(minimum, swaps);
    }

    return minimum;
}

int main()
{
    int N, L;

    while (scanf("%d %d\n", &N, &L) && N != 0)
    {
        vector< int > V(L);

        for (int i = 0; i < L; ++i)
        {
            int key;
            scanf("%d", &key);
            V[i] = key;
        }

        printf("%d\n", MinimizeSwaps(V, N));
    }
}