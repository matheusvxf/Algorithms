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

#define WEIGHT 1
#define POSITION 0

inline long long int DynamicHeapRec(int Q[1000][2], int N, int i, int k, int a)
{   
    if (k == 0 || k > N - i)
        return INF;
    if (i == N - 1)
        return 0;
    return min(DynamicHeapRec(Q, N, i + 1, k, a + Q[i][WEIGHT]) + (a + Q[i][WEIGHT]) * (Q[i + 1][POSITION] - Q[i][POSITION]), DynamicHeapRec(Q, N, i + 1, k - 1, 0));
}

long long int DynamicHeapInt(int Q[1000][2], int N, int i, int k, int a)
{
    map< pair< int, pair< int, int > >, long long int > cache;
    stack< vector< int > > rec_stack;
    deque< vector< int > > rec_queue;
    vector< int > parameter;
    int c_i = i, c_k = k, c_a = a;

    rec_queue.push_back({ i, k, a });

    while (!rec_queue.empty())
    {
        parameter = rec_queue.back(); rec_queue.pop_back();
        c_i = parameter[0]; c_k = parameter[1]; c_a = parameter[2];
        rec_stack.push({ c_i, c_k, c_a });

        if (c_k != 0 && c_k <= N - c_i && c_i != N - 1)
        {
            rec_queue.push_back({ c_i + 1, c_k, c_a + Q[c_i][WEIGHT] });
            rec_queue.push_back({ c_i + 1, c_k - 1, 0 });
        }
    }

    while (!rec_stack.empty())
    {
        parameter = rec_stack.top(); rec_stack.pop();
        c_i = parameter[0]; c_k = parameter[1]; c_a = parameter[2];
        
        if (c_k == 0 || c_k > N - c_i)
            cache[{c_i, { c_k, c_a } }] = INF;
        else if (c_i == N - 1)
            cache[{c_i, { c_k, c_a } }] = 0;
        else
            cache[{c_i, { c_k, c_a } }] = min(cache[{c_i + 1, { c_k, c_a + Q[c_i][WEIGHT] } }] + (c_a + Q[c_i][WEIGHT]) * (Q[c_i + 1][POSITION] - Q[c_i][POSITION]), cache[{c_i + 1, { c_k - 1, 0 }}]);
    }
    
    return cache[{i, { k, a }}];
}

int main(){
    int N, K;

    while(scanf("%d %d\n", &N, &K) != EOF) {
        //vector< pair< int, int > > Q(N);
        int Q[1000][2];

        for (int i = 0; i < N; ++i)
        {
            int pos, weight;
            scanf("%d %d\n", &pos, &weight);
            Q[i][0] = pos;
            Q[i][1] = weight;
        }

        printf("%lld\n", DynamicHeapInt(Q, N, 0, K, 0));
    }
}
