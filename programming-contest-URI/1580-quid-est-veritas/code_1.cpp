#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <sstream>
#include <string.h>

using namespace std;

const long long int mod = 1e9 + 7;
vector<int> prime;

void generate_prime(int limit = 1000){
    bool flag;

    prime.push_back(2);
    for(register int i = 3; i <= limit; ++i) {
        flag = true;
        for(auto it = prime.begin(); it != prime.end(); ++it){
            if(i % *it == 0) {
                flag = false;
                break;
            }
        }
        if(flag)
            prime.push_back(i);
    }
}

int* factors(int n){
    int *prime_factor = new int[1000];
    memset(prime_factor, 0, sizeof(int) * 1000);

    for(auto it = prime.begin(); it != prime.end(); ++it){
        while(n % *it == 0){
            n = n / *it;
            prime_factor[*it]++;
        }
    }
    return prime_factor;
}

int main(){
    int alphabet[27], len;
    long long int res;
    int *prime_factor, *tmp, **factor_table;
    string str;

    generate_prime(1000);
    prime_factor = new int[1000];

    while(cin >> str) {
        len = str.size();
        res = 1;
        factor_table = new int*[len + 1];
        memset(factor_table, 0, sizeof(int*) * (len + 1));
        memset(prime_factor, 0, sizeof(int) * 1000);
        memset(alphabet, 0, sizeof(int) * 27);

        for(register uint i = 0; i < len; ++i) {
            alphabet[str[i] - 'A']++;
        }

        for(register uint i = 2; i <= len; ++i) {
            tmp = factors(i);
            factor_table[i] = tmp;

            for(auto it = prime.begin(); it != prime.end(); ++it){
                prime_factor[*it] += tmp[*it];
            }
        }

        for(register uint i = 0; i < 27; ++i) {
            if(alphabet[i] > 1){
                for(auto it = prime.begin(); it != prime.end(); ++it){
                    prime_factor[*it] -= factor_table[alphabet[i]][*it];
                }
            }
        }

        for(auto it = prime.begin(); it != prime.end(); ++it){
            while(prime_factor[*it] > 0){
                res = (res * (*it % mod)) % mod;
                prime_factor[*it]--;
            }
        }

        cout << res << endl;
        
        for(register uint i = 2; i < len + 1; ++i)
            if(factor_table[i])
                delete[]factor_table[i];
        delete[]factor_table;
    }
}
