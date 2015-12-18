#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <string>
#include <map>
#include <stdio.h>

using namespace std;

#define all(Q) Q.begin(), Q.end()

int main() {
    int N;
    map< int, int > S;

    scanf("%d\n", &N);

    for (int i = 0; i < N; ++i)
    {
        int num;
        scanf("%d\n", &num);
        S[num]++;
    }

    for (auto it = S.begin(); it != S.end(); ++it)
    {
        printf("%d aparece %d vez(es)\n", it->first, it->second);
    }
}
