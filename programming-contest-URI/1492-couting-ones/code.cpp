#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <unordered_map>

using namespace std;

#define uint64 unsigned long long int
#define DEBUG 0
#define FIND(Q, a) (Q.find(a) != Q.end())


deque< int > Dec2Bin(uint64 a)
{
    deque< int > res;

    if (a == 0)
        res.push_back(0);

    while (a)
    {
        res.push_back(a % 2);
        a /= 2;
    }

    return res;
}

uint64 fac(int N)
{
    static unordered_map< int, uint64 > cache{ { 0, 1 }, { 1, 1 } };

    if (FIND(cache, N))
        return cache[N];

    return cache[N] = N * fac(N - 1);
}

uint64 comb(int N, int i)
{
    if (N < i)
        return 1;
    return fac(N) / (fac(N - i) * fac(i));
}

uint64 CountOnes(deque< int > vec, int add = 0) {
    int size = vec.size();
    uint64 total = 0;

    if (vec.size() == 1)
        return (add + vec[0]);

    for (int i = 1; i <= size - 1; ++i)
    {
        total += (i + add) * comb(size - 1, i);
    }

    vec.pop_back();
    while (!vec.empty() && vec.back() == 0)
        vec.pop_back();

    if (vec.empty())
        vec.push_back(0);

    total += CountOnes(vec, add + 1);

    return total;
}

int main() {
    uint64 A, B;

    while (scanf("%llu %llu\n", &A, &B) != EOF) 
    {
        auto a = Dec2Bin(A - 1);
        auto b = Dec2Bin(B);

        printf("%lld\n", CountOnes(b) - CountOnes(a));
    }
}
