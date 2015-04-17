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
    int N;

    scanf("%d\n", &N);
    while (N--)
    {
        string str;

        getline(cin, str);

        reverse(str.begin(), str.begin() + str.size() / 2);
        reverse(str.begin() + str.size() / 2, str.end());

        printf("%s\n", str.c_str());
    }
}
