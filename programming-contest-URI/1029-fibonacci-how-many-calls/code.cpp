#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

class fibonacci
{
public:
    static map< long long int, long long int> fib_cache;

    static long long int fib(long long int n, long long int b)
    {
        auto it = fib_cache.find(n);

        if (it != fib_cache.end())
            return it->second;

        if (n % 2 == 0) // even
        {
            long long int k = n / 2;
            fib_cache[n] = (fib(k, b) * (fib(k, b) + 2 * fib(k - 1, b)));
        }
        else
        {
            long long int k = (n - 1) / 2;
            fib_cache[n] = (fib(k + 1, b) * fib(k + 1, b) + fib(k, b) * fib(k, b));
        }

        return fib_cache[n];
    }

    static void reset()
    {
        fib_cache.clear();
        fib_cache.insert({ { 0, 0 }, { 1, 1 }, { 2, 1 } });
    }
};

map<long long int, long long int> fibonacci::fib_cache = { { 0, 0 }, { 1, 1 }, { 2, 1 } };

int main() {
    int N, n;

    cin >> N;
    while (N--)
    {
        cin >> n;
        int X = n - 1, Y = n - 2;
        int calls = (Y < 0 ? 1 : (2 * fibonacci::fib(X + 1, 10) + 2 * fibonacci::fib(Y + 1, 10) - 2));
        int result = fibonacci::fib(n, 10);

        printf("fib(%d) = %d calls = %d\n", n, calls, result);
    }
}
