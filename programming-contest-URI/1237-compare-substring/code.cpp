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

int LongestCommonSubstring(const char str_1[], size_t size_1, const char str_2[], size_t size_2)
{
    vector< vector< int > > m(size_1);
    int longer = 0;

    for (int i = 0; i < size_1; ++i)
        m[i].resize(size_2);

    for (int i = 0; i < size_1; ++i)
    {
        for (int j = 0; j < size_2; ++j)
        {
            if (str_1[i] == str_2[j])
            {
                if (i > 0 && j > 0)
                    m[i][j] = m[i - 1][j - 1] + 1;
                else
                    m[i][j] = 1;
            }
            else
                m[i][j] = 0;
            longer = max(longer, m[i][j]);
        }
    }
    return longer;
}

int main() {
    string str_1;
    string str_2;

    while (getline(cin, str_1))
    {
        int longer = 0, acumulator = 0;
        getline(cin, str_2);

        printf("%d\n", LongestCommonSubstring(str_1.c_str(), str_1.size(), str_2.c_str(), str_2.size()));
    }
}
