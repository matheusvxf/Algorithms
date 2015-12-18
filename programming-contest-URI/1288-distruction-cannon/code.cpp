#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define all(S) S.begin(), S.end()

struct Item
{
    int weight;
    int value;
};

int knapsack(vector< Item > items, int capacity) {
    int num_items = items.size();
    vector< vector< int > > S(num_items);
	int i;

    for (i = 0; i < num_items; ++i)
    {
		S[i].resize(capacity + 1);
        fill(all(S[i]), 0);
	}

    i = num_items - 1;
	for(int c = 0; c <= capacity; ++c) {
		if(items[i].weight > c)
			S[i][c] = 0;
		else
			S[i][c] = items[i].value;
	}

    while (--i >= 0)
    {
        for (int c = 0; c <= capacity; ++c)
        {
            if (items[i].weight > c)
                S[i][c] = S[i + 1][c];
            else
                S[i][c] = max(S[i + 1][c], S[i + 1][c - items[i].weight] + items[i].value);
        }
    }

    return S[0][capacity];
}

int main() {
    int num_test, N, P, K, R, damage;

    scanf("%d", &num_test);

    while (num_test--)
    {
        scanf("%d", &N);
        vector< Item > items(N);

        for (int i = 0; i < N; ++i)
            scanf("%d %d", &items[i].value, &items[i].weight);

        scanf("%d", &K);
        scanf("%d", &R);

		damage = knapsack(items, K);

        printf("%s", (damage >= R ? "Missao completada com sucesso\n" : "Falha na missao\n"));
	}
}
