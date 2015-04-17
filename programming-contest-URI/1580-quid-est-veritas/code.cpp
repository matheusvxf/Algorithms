#include <iostream>
#include <deque>
#include <string.h>
#include <stdio.h>

using namespace std;

#define DEBUG_GCD 0

const long long int mod = 1e9 + 7;

long long int GCD(long long int p_a, long long int p_b) {
    long long int a, b, res, tmp;
    a = max(p_a, p_b);
    b = min(p_a, p_b);

    if(b == 0)
        res = a;
    else {
        while(a % b != 0) {
            tmp = b;
            b = a % b;
            a = tmp;
        }
        res = b;
    }

#if (DEBUG_GCD == 1)
    cerr << "GCD(" << p_a << ", " << p_b << ") = " << res << endl;
#endif

    return res;
}

int main() {
    int alphabet[27], A, a;
    long long int num, den, res, gcd;
    deque< int > factors;
    string str;

    while(cin >> str) {
        factors.clear();
        A = str.size();
        memset(alphabet, 0, sizeof(int) * 27);
        num = den = a = 1;
        res = 0;

        for(register uint i = 0; i < A; ++i) {
            alphabet[str[i] - 'A']++;
        }

        for(register uint i = 2; i <= A; ++i)
            factors.push_back(i);

        for(register uint i = 0; i < 27; ++i) {
            for(register uint j = 2; j <= alphabet[i]; ++j){
                den = j;
                auto it = factors.begin();
                while(den > 1) {
                    gcd = GCD(*it, den);
                    den /= gcd;
                    *it /= gcd;
                    it++;
                }
                if(*it == 1)
                    factors.erase(it);
            }
        }

        for(auto it = factors.begin(); it != factors.end(); ++it)
        {
            num *= *it;
            num %= mod;
        }
        
        cout << num << endl;
    }
}
