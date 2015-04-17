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

int main() {
    int T;

    scanf("%d\n", &T);
    while (T--)
    {
        string str;
        int Q;

        cin >> str;
        scanf("%d\n", &Q);

        for (int i = 0; i < Q; ++i)
        {
            string sub;
            bool flag = false;
            cin >> sub;

            auto it_2 = sub.begin();
            for (auto it = str.begin(); it != str.end() && it_2 != sub.end(); ++it)
            {
                if (*it == *it_2)
                    it_2++;
            }

            printf("%s\n", it_2 == sub.end() ? "Yes" : "No");
        }
    }
}
