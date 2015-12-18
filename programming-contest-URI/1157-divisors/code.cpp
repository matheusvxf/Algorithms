#include <iostream>
#include <deque>
#include <string.h>
#include <stdio.h>

using namespace std;

long long int mod = 1000000009;

int main() {
    int N;

    cin >> N;

    for(register int i = 1; i <= N; ++i)
        if(N % i == 0)
            cout << i << endl;
}
