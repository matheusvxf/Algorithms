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
#define pi 3.14159

int main() {
    int N;

    scanf("%d\n", &N);
    while (N--)
    {
        string str;
        int shift;

        cin >> str >> shift;

        for (int i = 0; i < str.size(); ++i)
        {
            char c = str[i];
            
            c = (c - shift < 'A' ? 'Z' - (shift - (c - 'A')) + 1 : c - shift);
            str[i] = c;
        }

        printf("%s\n", str.c_str());
    }
}
