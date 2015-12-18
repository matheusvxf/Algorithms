#include <iostream>
#include <deque>
#include <string.h>
#include <stdio.h>

using namespace std;

long long int mod = 1000000009;

int main() {
    int N;
    long long int res;

    while(cin >> N && N != 0) {
    	res = 1;

    	for(register uint i = 4; i <= N; ++i) {
    		res *= i;
    		res %= mod;
    	}

    	cout << res << endl;
    }
}
