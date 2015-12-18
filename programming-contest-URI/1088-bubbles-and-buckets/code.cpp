#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
#include <deque>
#include <unordered_map>
#include <stack>

using namespace std;

#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)
#define all(Q) Q.begin(), Q.end()
#define FIND(Q, a) Q.find(a) != Q.end()

class Residence
{
public:
    long long int residents, consume;
    long long int avr;

    Residence() : Residence(0, 0) {}
    Residence(long long int r, long long int c) : residents(r), consume(c), avr(c / r) {}

    bool operator<(const Residence& a) const
    {
        return avr < a.avr;
    }
};

int main() {
    int N;

    while (scanf("%d\n", &N) && N != 0)
    {
        int num;
        deque< int > Q;
        sort(all(Q));

        for (int i = 0; i < N; ++i)
        {

        }
    }
}
