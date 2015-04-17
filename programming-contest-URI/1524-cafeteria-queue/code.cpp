#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>
#include <string>
#include <string.h>

using namespace std;

class mycomparison
{
    bool reverse;
public:
    mycomparison(const bool& revparam = true)
    {
        reverse = revparam;
    }
    bool operator() (const int& lhs, const int&rhs) const
    {
        if (reverse) return (lhs>rhs);
        else return (lhs<rhs);
    }
};

#define all(Q) Q.begin(), Q.end()

int main() {
    int N, K;

    while (scanf("%d %d\n", &N, &K) != EOF)
    {
        priority_queue< int, vector< int >, mycomparison > Q;
        int prev = 0, num_set;
        int dst = 0;

        for (int i = 0; i < N - 1; ++i)
        {
            int tmp;
            scanf("%d", &tmp);
            Q.push(tmp - prev);
            prev = tmp;
        }

        num_set = N;
        while (num_set > K)
        {
            dst += Q.top(); Q.pop(); num_set--;
        }

        printf("%d\n", dst);
    }
}
