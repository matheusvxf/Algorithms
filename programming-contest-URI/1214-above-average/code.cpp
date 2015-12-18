#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
#include <bitset>

using namespace std;

#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)
#define all(Q) Q.begin(), Q.end()

int main() {
    int C;

    scanf("%d\n", &C);
    while (C--) 
    {
        int N;
        int grade[1000];
        int total = 0, above_avr = 0;
        float avr;

        scanf("%d", &N);

        for (int i = 0; i < N; ++i)
        {
            int n;
            scanf("%d", &n);
            total += n;
            grade[i] = n;
        }

        avr = (float)total / (float)N;

        for (int i = 0; i < N; ++i)
        {
            if (grade[i] > avr)
                above_avr++;
        }

        printf("%.3f%%\n", (float)above_avr / (float)N * 100.0);
    }
}
