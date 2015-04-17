#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <sstream>
#include <stack>
#include <list>
#include <array>
#include <queue>
#include <unordered_map>
#include <string.h>

using namespace std;

#define INF (long long int)1e15
#define all(Q) Q.begin(), Q.end()

int Solve(vector< int >& Q, int n, int i, int t, int a)
{
    if (t == 0 || t > n - 1 - i)
        return INF;
    if (t == n - 1 - i)
        return Solve(Q, n, i + 1, t, a + Q[i]);
    if (i == n - 1)
        return a + Q[i];
    return min(max(Solve(Q, n, i + 1, t - 1, 0), a + Q[i]), Solve(Q, n, i + 1, t, a + Q[i]));
}

int main(){
    int T;

    scanf("%d\n", &T);
    while(T--) {
        int nPainels, trucks, freight;
        vector< int > Q;

        scanf("%d %d %d\n", &nPainels, &trucks, &freight);

        for (int i = 0; i < nPainels; ++i)
        {
            int num;
            scanf("%d", &num);
            Q.push_back(num);
        }

        int maximum = Solve(Q, Q.size(), 0, trucks, 0);

        printf("%d $%d\n", maximum, maximum * freight);
    }
}
