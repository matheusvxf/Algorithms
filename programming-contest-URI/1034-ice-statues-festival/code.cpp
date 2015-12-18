#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

#define all(Q) Q.begin(), Q.end()
#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)
#define INF (int)1e10

class Solve
{
public:
    vector< int > blocks;
    vector< int > m;
    int M;

    void init(int M)
    {
        this->M = M;
        m.resize(M + 1);
        fill(all(m), -1);
        m[0] = 0;
    }

    int DynamicBlocks(int i)
    {
        if (m[i] != -1)
            return m[i];
        m[i] = INF;
        for (auto b : this->blocks)
        {
            if (i - b >= 0)
                m[i] = min(m[i], DynamicBlocks(i - b) + 1);
        }
        return m[i];
    }
};

int DynamicBlocks(int M, vector< int >& blocks)
{
    vector< int > m(M + 1);

    m[0] = 0;

    for(int i = 1; i <= M; ++i) {
        m[i] = INF;

        foreach(blocks, block) {
            if (i - *block >= 0)
                m[i] = min(m[i], m[i - *block] + 1);
        }
    }

    return m[M];
}

int main() {
    int T;

    scanf("%d\n", &T);
    while(T--) {
        int N, M, acumulator = 0;
        long long int multiplier = 1;
        Solve solve;
        vector< int > &blocks = solve.blocks;

        scanf("%d %d\n", &N, &M);

        for(int i = 0; i < N; ++i){
        	int num;
        	scanf("%d", &num);
        	blocks.push_back(num);
        }

        sort(all(blocks));

        multiplier = blocks.back();
        for (int i = blocks.size() - 2; i >= 0; --i)
        {
            if (!(multiplier % blocks[i] == 0))
                multiplier *= blocks[i];
        }

        if (M >= multiplier)
        {
            acumulator += ((M / multiplier) * multiplier) / blocks.back();
            M %= multiplier;
        }

        reverse(all(blocks));

        solve.init(M);
        printf("%d\n", acumulator + solve.DynamicBlocks(M));
    }
}
