#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>

using namespace std;

#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)

bool IsPrime(int n, vector< int > &PrimeList)
{
    int n_root = (int)sqrt(n);

    for (auto it = PrimeList.begin(); it != PrimeList.end() && *it < n_root; ++it)
    {
        if (n % *it == 0)
            return false;
    }
    PrimeList.push_back(n);
    return true;
}

bool TestPrime(int n)
{
    int n_root = (int)sqrt(n);
    static vector< int > PrimeList{ 2, 3 };

    for (int i = PrimeList.back(); i < n_root; ++i)
        IsPrime(i, PrimeList);

    return IsPrime(n, PrimeList);
}

int main()
{
    int N;

    scanf("%d", &N);
    while (N--)
    {
        int x;

        scanf("%d", &x);
        printf("%s\n", TestPrime(x) ? "Prime" : "Not Prime");
    }
}