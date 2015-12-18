#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)

int main() {
    int entire, fraction;
    vector< long long int > notes = { 100, 50, 20, 10, 5, 2 };
    vector< long long int > coins = { 1, 50, 25, 10, 5, 1 };

    while (scanf("%d.%d", &entire, &fraction) != EOF)
    {
        printf("NOTAS:\n");
        foreach(notes, it)
        {
            int note = *it;

            printf("%d nota(s) de R$ %d.00\n", entire / note, note);
            entire %= note;
        }

        printf("MOEDAS:\n");
        printf("%d moeda(s) de R$ %d.00\n", entire, 1);

        for (int i = 1; i < coins.size(); ++i)
        {
            int coin = coins[i];

            printf("%d moeda(s) de R$ 0.%02d\n", fraction / coin, coin);
            fraction %= coin;
        }
    }
}
