#include <iostream>
#include <deque>
#include <string.h>
#include <stdio.h>

using namespace std;

#define DEBUG_GCD 0

const long long int mod = 1e9 + 7;

long long int factorial(int a) {
    if (a <= 1)
        return 1;
    else
        return a * factorial(a - 1);
}

int main() {
    int M, N;

    while(cin >> M >> N){
        cout << factorial(M) + factorial(N) << endl;
    }
}
