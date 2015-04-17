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
        int L;
        int hash = 0;
        
        scanf("%d\n", &L);
        for (int i = 0; i < L; ++i)
        {
            char c;
            int position = 0;
            while (scanf("%c", &c) && c != '\n')
            {
                hash += i + (c - 'A') + position++;
            }
        }

        printf("%d\n", hash);
    }
}
