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
#define pi 3.14159

class Camera
{
public:
    long long int a, b;

    bool operator<(const Camera& b) const
    {
        if (a < b.a)
            return true;
        else if (a > b.a)
            return false;
        else
            return this->b < b.b;
    }
};

int BinarySearch(vector< Camera > &Q, long long int x)
{
    int lower_bound = 0, upper_bound = Q.size() - 1;

    while (lower_bound < upper_bound)
    {
        int avr = (lower_bound + upper_bound) / 2;

        if (Q[avr].a <= x && x <= Q[avr].b)
            return avr;
        
        if (x < Q[avr].a)
        {
            upper_bound = avr - 1;
        }
        else
        {
            lower_bound = avr + 1;
        }
    }

    return lower_bound;
}

int main() {
    int T, test = 1;

    scanf("%d\n", &T);
    while (T--)
    {
        long long int N;
        int C, E;
        vector< Camera > Q;
        int covered = 0;
        
        scanf("%lld %d\n", &N, &C);

        Q.resize(C);
        for (int i = 0; i < C; ++i)
        {
            long long int a, b;
            scanf("%lld %lld\n", &a, &b);
            Q[i].a = a;
            Q[i].b = b;
        }

        sort(all(Q));
        scanf("%d\n", &E);

        for (int i = 0; i < E; ++i)
        {
            long long int x;
            scanf("%lld", &x);
            int index = BinarySearch(Q, x);
            if (Q[index].a <= x && x <= Q[index].b)
                covered++;
        }

        printf("Caso #%d: %d\n", test++, covered);
    }
}
