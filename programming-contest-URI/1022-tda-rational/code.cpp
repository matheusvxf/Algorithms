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

int GCD(int a, int b)
{
    int tmp;

    while (b != 0)
    {
        tmp = a;
        a = b;
        b = tmp % b;
    }

    return a;
}

int main() {
    int N;

    scanf("%d\n", &N);

    while (N--)
    {
        int n_1, d_1, n_2, d_2;
        int n, d, gcd;
        char op;

        scanf("%d / %d %c %d / %d\n", &n_1, &d_1, &op, &n_2, &d_2);
        
        if (op == '+')
        {
            n = (n_1 * d_2 + n_2 * d_1);
            d = (d_1 * d_2);
        }
        else if (op == '-')
        {
            n = (n_1 * d_2 - n_2 * d_1);
            d = (d_1 * d_2);
        }
        else if (op == '*')
        {
            n = (n_1 * n_2);
            d = (d_1 * d_2);
        }
        else if (op == '/')
        {
            n = (n_1 * d_2);
            d = (d_1 * n_2);
        }
        if (d < 0)
        {
            n *= -1;
            d *= -1;
        }
        gcd = GCD(n, d);
        gcd = (gcd < 0 ? -gcd : gcd);

        printf("%d/%d = %d/%d\n", n, d, n / gcd, d / gcd);
    }
}
