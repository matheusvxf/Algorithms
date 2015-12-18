#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Pizza {
	int time;
	int amount;
};

#define DEBUG 0

void motoboy(Pizza *p_pizza, int n_pizza, int capacity) {
	int **S = new int*[n_pizza];
	int i;

#if (DEBUG == 1)
	printf("motoboy(%d, %d)\n", n_pizza, capacity);
#endif

	for(i = 0; i < n_pizza; ++i) {
		S[i] = new int[capacity + 1];
		memset(S[i], 0, sizeof(int) * (capacity + 1));
	}

	i = n_pizza - 1;
	for(register uint c = 0; c <= capacity; ++c) {
		if(p_pizza[i].amount > c)
			S[i][c] = 0;
		else
			S[i][c] = p_pizza[i].time;
	}

	while(--i >= 0) {
		for(register uint c = 0; c <= capacity; ++c) {
			if(p_pizza[i].amount > c)
				S[i][c] = S[i + 1][c];
			else
				S[i][c] = max(S[i + 1][c], S[i + 1][c - p_pizza[i].amount] + p_pizza[i].time);
		}
	}

	cout << S[0][capacity] << " min." << endl;

#if (DEBUG == 1)
	for(register uint i = 0; i < n_pizza; ++i) {
		for(register uint j = 0; j <= capacity; ++j)
			cout << S[i][j] << " ";
		cout << endl;
	}
#endif

	for(i = 0; i < n_pizza; ++i)
		delete[]S[i];
}

int main() {
	int N, P;
	Pizza *p_pizza;

	while(cin >> N && N != 0){
		cin >> P;
		p_pizza = new Pizza[N];

		for(register uint i = 0; i < N; ++i)
			cin >> p_pizza[i].time >> p_pizza[i].amount;

		motoboy(p_pizza, N, P);

		delete[]p_pizza;
	}
}
