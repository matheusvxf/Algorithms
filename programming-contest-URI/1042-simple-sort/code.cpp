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
#include <string>

using namespace std;

#define uint unsigned int
#define FIND(Q, q) (Q.find(q) != Q.end())
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)
#define INF ((int)10e6)
#define all(Q) Q.begin(), Q.end()

int main() {
    vector< int > Q;
    stringstream buffer;
    int x;

    while (cin >> x)
    {
        Q.push_back(x);
        buffer << x << endl;
    }

    sort(all(Q));

    foreach(Q, it)
        printf("%d\n", *it);

    printf("\n%s", buffer.str().c_str());
}
