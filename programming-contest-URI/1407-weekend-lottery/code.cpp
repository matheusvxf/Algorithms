#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)
#define all(Q) Q.begin(), Q.end()
#define LOW 0
#define HIGH 1

class Number
{
public:
    int number_;
    int counter_;

    Number() : number_(0), counter_(0) {}
};

bool compare(const Number& a, const Number& b)
{
    if (a.counter_ == b.counter_)
        return a.number_ < b.number_;
    else
        return a.counter_ < b.counter_;
}

int main()
{
    int N, C, K;

    while (scanf("%d %d %d\n", &N, &C, &K) && N != 0)
    {
        vector< Number > Q;

        Q.resize(K);
        for (int i = 0; i < K; ++i)
            Q[i].number_ = i + 1;

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                int num;
                scanf("%d", &num);
                Q[num - 1].counter_++;
            }
        }

        sort(all(Q), compare);
        int smaller = Q[0].counter_;
        int i = 0;

        printf("%d", Q[i++].number_);

        while (i < K && smaller == Q[i].counter_)
        {
            printf(" %d", Q[i++].number_);
        }

        printf("\n");



    }
}
