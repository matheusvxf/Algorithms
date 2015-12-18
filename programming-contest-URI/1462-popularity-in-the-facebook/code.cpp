#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cassert>
#include <string.h>
#include <stdio.h>
 
using namespace std;
 
#define uint unsigned int
#define INF 10e6
#define FIND(Q, q) (Q.find(q) != Q.end())
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)
#define all(Q) Q.begin(), Q.end()

class Sort
{
public:
    bool operator()(const long long int& a, const long long int& b) const
    {
        return a > b;
    }
} s;

int main()
{
    long long int N;

    while (scanf("%lld\n", &N) != EOF)
    {
        vector< long long int > d;
        long long int l = 0;
        long long int sum_until_l = 0, sum_after_l = 0, total = 0;

        for (long long int i = 0; i < N; ++i)
        {
            long long int degree;
            scanf("%lld", &degree);
            d.push_back(degree);
            total += degree;
        }

        sort(all(d), s);

        for (long long int k = 1; k < N; ++k)
        {
            sum_until_l += d[k - 1];
            l = k;
            if (d[k - 1] > d[k])
            {
                break;
            }
        }

        for (long long int i = l; i < N; ++i)
        {
            sum_after_l += min(d[i], l);
        }

        if ((total % 2 == 0) && (sum_until_l <= l * (l - 1) + sum_after_l) && (total <= N * (N - 1)))
            printf("possivel\n");
        else
            printf("impossivel\n");
    }
}
