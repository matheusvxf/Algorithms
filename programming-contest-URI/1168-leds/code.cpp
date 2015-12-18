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
#include <unordered_map>

using namespace std;

int main() {
    int N;

    scanf("%d\n", &N);
    while (N--)
    {
        unordered_map< char, int > map{ { '0', 6 }, { '1', 2 },
        { '2', 5 }, { '3', 5 }, { '4', 4 }, { '5', 5 }, { '6', 6 },
        { '7', 3 }, { '8', 7 }, { '9', 6 } };
        char c;
        int acumulator = 0;

        while (scanf("%c", &c) && c != '\n')
        {
            acumulator += map[c];
        }

        printf("%d leds\n", acumulator);
    }
}
