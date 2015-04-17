#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <string.h>

using namespace std;

#define all(Q) Q.begin(), Q.end()
#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)

int DynamicAnd(vector< int >& Q, int i, int k, int n)
{
    int N = Q.size();
    int res, select_i, ignore_i, tmp;

    if (k == 0)
        return 0;
    if (k == 1)
    {
        if (i == N - 1)
            return n & Q[i];
        else
            return max(DynamicAnd(Q, i + 1, 1, n), n & Q[i]);
    }
    else
    {
        if (N - i < k)
            return 0;
        else
            return max(DynamicAnd(Q, i + 1, k, n), DynamicAnd(Q, i + 1, k - 1, n & Q[i]));
    }
}

int main() {
    int T;

    scanf("%d\n", &T);
    while (T--)
    {
        int N, K;
        vector< int > Q;
        map< int, vector< int > > num_set;
        int res = (1 << 30) - 1;
        
        scanf("%d %d\n", &N, &K);

        for (int i = 0; i < N; ++i)
        {
            int num;
            scanf("%d", &num);
            Q.push_back(num);
        }

        //sort(all(Q));
        res = DynamicAnd(Q, 0, K, (1 << 30) - 1);

        printf("%d\n", res);
    }
}
