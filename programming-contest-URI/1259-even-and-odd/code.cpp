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

class Sort
{
public:

    bool operator()(const int& a, const int& b) const
    {
        if (a % 2 == 0 && b % 2 != 0)
            return true;
        if (a % 2 != 0 && b % 2 == 0)
            return false;
        if (a % 2 == 0 && b % 2 == 0)
            return a < b;
        return a > b;
    }
} S;

int main() {
    int N, num;
    vector< int > Q;

    scanf("%d\n", &N);
    Q.resize(N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d\n", &num);
        Q[i] = num;
    }

    sort(all(Q), S);

    for (int i = 0; i < N; ++i)
    {
        printf("%d\n", Q[i]);
    }
}
