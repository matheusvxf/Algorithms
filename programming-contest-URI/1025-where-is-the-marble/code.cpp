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

int lower_bound(vector< int > &v, int n)
{
    int lower_bound = 0, upper_bound = v.size() - 1;

    while (lower_bound <= upper_bound)
    {
        int avr = (lower_bound + upper_bound) / 2;

        if (v[avr] == n)
        {
            while (avr >= 0 && v[avr] == n)
                avr--;
            avr++;

            return avr;
        }

        if (v[avr] < n)
        {
            lower_bound = avr + 1;
        }
        else
        {
            upper_bound = avr - 1;
        }
    }

    return lower_bound;
}

int main() {
    int N, Q, case_counter = 1;

    while (scanf("%d %d\n", &N, &Q) && N != 0)
    {
        vector< int > v(N);

        for (int i = 0; i < N; ++i)
        {
            int n;
            scanf("%d\n", &n);
            v[i] = n;
        }

        sort(all(v));

        printf("CASE# %d:\n", case_counter++);
        for (int i = 0; i < Q; ++i)
        {
            int n, k;
            scanf("%d\n", &n);
            k = lower_bound(v, n);

            if (k < v.size() && v[k] == n)
            {
                printf("%d found at %d\n", n, k + 1);
            }
            else
            {
                printf("%d not found\n", n);
            }
        }
    }
}
