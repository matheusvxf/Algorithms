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
    int N, L, C;

    while (scanf("%d %d %d\n", &N, &L, &C) != EOF)
    {
        int pages = 1;
        int lines = 1;
        int characters = 0;
        string str;

        cin >> str;
        characters += str.size();
        for (int i = 1; i < N; ++i)
        {
            cin >> str;
            if (str.size() + characters + 1 <= C)
            {
                characters += str.size() + 1;
            }
            else
            {
                characters = str.size();
                if (lines + 1 <= L)
                    lines++;
                else
                {
                    lines = 1;
                    pages++;
                }
            }

        }

        getline(cin, str);
        printf("%d\n", pages);
    }
}
