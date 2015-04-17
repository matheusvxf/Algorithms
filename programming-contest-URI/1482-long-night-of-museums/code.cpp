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

int main() {
    int N;

    while (scanf("%llu %llu\n", &A, &B) != EOF) 
    {
        auto a = Dec2Bin(A - 1);
        auto b = Dec2Bin(B);

        printf("%lld\n", CountOnes(b) - CountOnes(a));
    }
}
