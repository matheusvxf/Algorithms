#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

#define uint unsigned int
#define FIND(Q, q) (Q.find(q) != Q.end())
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)
#define INF ((int)10e6)

static vector< int > prime_number{ 2, 3, 5 };

void Generate_prime(int amount = 3501)
{
    int i = 7, counter = 0;

    amount -= 3;
    while (counter < amount)
    {
        bool is_prime = true;

        foreach(prime_number, it)
        {
            int n = *it;

            if (n > (int)sqrt(i))
                break;
            if (i % n == 0)
                is_prime = false;
        }
        if (is_prime)
        {
            prime_number.push_back(i);
            counter++;
        }
        i++;
    }
}

int main() {
    int N;

    Generate_prime();

    while (scanf("%d", &N) && N != 0)
    {
        vector< int > line;

        for (int i = 1; i <= N; ++i)
            line.push_back(i);

        for (int i = 0; i < N - 1; ++i)
        {
            int prime = prime_number[i];
            int shift = prime % line.size();

            rotate(line.begin(), line.begin() + shift, line.end());

            line.pop_back();
        }

        printf("%d\n", line[0]);
    }
}
