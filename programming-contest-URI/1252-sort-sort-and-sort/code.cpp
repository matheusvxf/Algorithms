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
#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)

static inline bool is_odd(int a)
{
    return a % 2 != 0;
}

class Sort
{
public:
    int M;
    bool operator()(const int& a, const int& b) const
    {
        int a_mod = a % M;
        int b_mod = b % M;

        if (a_mod < b_mod)
            return true;
        else if (a_mod > b_mod)
            return false;
        else if (is_odd(a) && !is_odd(b))
            return true;
        else if (!is_odd(a) && is_odd(b))
            return false;
        else if (is_odd(a) && is_odd(b))
            return a > b;
        else
            return a < b;
    }
} obj;

int main() {
    int N, M;

    while (scanf("%d %d\n", &N, &M) && N != 0)
    {
        vector< int > Q(N);
        obj.M = M;

        for (int i = 0; i < N; ++i)
        {
            scanf("%d\n", &Q[i]);
        }

        std::sort(all(Q), obj);

        printf("%d %d\n", N, M);

        foreach(Q, it)
            printf("%d\n", *it);
    }

    printf("%d %d\n", N, M);
}
