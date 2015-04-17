#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

#define all(S) S.begin(), S.end()

inline int plus_mod(int a, int b, int div)
{
    return ((a % div) + (b % div) ) % div;
}

inline int multi_mod(int a, int b, int div)
{
    return ((a % div) * (b % div)) % div;
}

inline int div_mod(int a, int b, int div)
{
    return ((a % div) / (b % div)) % div;
}

class solution
{
public:
    static unordered_map< int, int > cache;

    static int mod(int digites, int n)
    {
        auto it = cache.find(digites);

        if (it != cache.end())
            return it->second;

        return cache[digites] = plus_mod(multi_mod(mod(digites - 1, n), 10, n), 1, n);
    }

    static int ones(int n)
    {
        int digites = 1;

        cache.clear();
        cache.insert(make_pair(1, 1 % n));

        while (1)
        {
            if (mod(digites, n) == 0)
                return digites;
            digites++;
        }

        return -1;
    }
};

unordered_map< int, int > solution::cache;

int main() {
    int n;

    while (scanf("%d", &n) != EOF)
    //for (int n = 1; n < 10000; ++n)
    {
        if (n % 2 != 0 && n % 5 != 0)
            printf("%d\n", solution::ones(n));
    }
}
