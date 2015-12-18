#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>

using namespace std;

#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)
#define all(Q) Q.begin(), Q.end()

int fib(int n)
{
    if (n <= 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int T;

    scanf("%d", &T);

    while (T--)
    {
        int c;

        while ((c = getchar()) && c != '\n')
        {

        }
        cout << fib(10000) << endl;
    }
}
