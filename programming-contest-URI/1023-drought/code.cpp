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
    int N, i = 1;

    while (scanf("%d\n", &N) && N != 0)
    {
        set< Residence > Q;
        long long int total_consume = 0, total_residents = 0;

        if (i > 1)
            printf("\n");

        for (int j = 0; j < N; ++j)
        {
            long long int residents, consume;
            scanf("%lld %lld\n", &residents, &consume);
            total_residents += residents;
            total_consume += consume;

            auto it = Q.find(Residence(residents, consume));
            if (it != Q.end())
            {
                Residence r = *it;
                Q.erase(it);
                Q.insert(Residence(r.residents + residents, r.consume + consume));
            }
            else
            {
                Q.insert(Residence(residents, consume));
            }
        }

        printf("Cidade# %d:\n", i++);
        auto it = Q.begin();
        printf("%lld-%lld", it->residents, it->avr);
        for (it++; it != Q.end(); ++it)
        {
            printf(" %lld-%lld", it->residents, it->avr);
        }
        printf("\n");
        printf("Consumo medio: %.2f m3.\n", floor((float)total_consume / (float)total_residents * 100) / (float)100);
    }
}
