#include <iostream>
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
    string str;

    while(cin >> str) {
        A = str.size();
        memset(alphabet, 0, sizeof(int) * 27);
        num = den = a = 1;
        res = 0;

        for(register uint i = 0; i < A; ++i) {
            alphabet[str[i] - 'A']++;
        }

        for(register uint i = 0; i < 27; ++i) {
            for(register uint j = 2; j <= alphabet[i]; ++j){
                num *= a++;
                den *= j;

                if(num / mod >= 1) {
                    gcd = GCD(num, den);
                    num /= gcd;
                    den /= gcd;
                }
            }
        }

        while(a <= A) {
            num *= a;

            if(den != 1) {
                gcd = GCD(num, den);
                num /= gcd;
                den /= gcd;
            } else {
                num %= mod;
            }

            a++;
        }

        num /= den;
        num %= mod;
        
        cout << num << endl;
    }
}
