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
    int T;

    scanf("%d", &T);

    while (T--)
    {
        set< int > sheep;
        int N, id;

        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
        {
            scanf("%d", &id);
            sheep.insert(id);
        }

        printf("%d\n", sheep.size());
    }
}
