#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
#include <bitset>

using namespace std;

#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)
#define all(Q) Q.begin(), Q.end()

int main() {
    unsigned long long int x, y;

    while (cin >> x >> y) 
    {
        cout << (x ^ y) << endl;
    }
}
