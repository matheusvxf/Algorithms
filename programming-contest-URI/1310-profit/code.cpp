#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main() {
    int N;

    while (cin >> N) {
        int cost, better = 0;
        int *reveneu = new int[N];

        cin >> cost;
        for (int i = 0; i < N; ++i)
            cin >> reveneu[i];

        for (int i = 1; i <= N; ++i)
        {
            int begin = 0, j = 0;
            int acumulator = 0;

            while (j < N)
            {
                acumulator += reveneu[j];
                acumulator -= cost;

                better = max(better, acumulator);

                j++;
                if (begin + i == j)
                {
                    acumulator -= reveneu[begin];
                    acumulator += cost;
                    begin++;
                }
            }
        }

        printf("%d\n", better);

        delete[]reveneu;
	}
}
