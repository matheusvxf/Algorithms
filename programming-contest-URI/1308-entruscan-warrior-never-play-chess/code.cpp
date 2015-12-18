#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>

using namespace std;

#define uint64 unsigned long long int
#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)

long long int search_lines(uint64 warriors)
{
    uint64 num = (-1 + (uint64)sqrt(1 + 8 * warriors)) / 2;

    return num;
}

int main()
{
    int T;

    scanf("%d", &T);
    while (T--)
    {
        long long int x;

        scanf("%lld", &x);
        printf("%d\n", search_lines(x));
    }
}