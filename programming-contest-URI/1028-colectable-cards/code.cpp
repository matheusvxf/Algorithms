#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <stdio.h>

using namespace std;

#define all(Q) Q.begin(), Q.end()
#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)
#define INF (int)1e10

template< class T >
T GCD(T a, T b)
{
    while (b != 0)
    {
        T t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int T;

    scanf("%d\n", &T);
    while (T--)
    {
        int A, B;

        scanf("%d %d\n", &A, &B);
        printf("%d\n", GCD(A, B));
        
    }
}
