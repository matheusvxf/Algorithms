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
        string str_1, str_2;
        string result;

        cin >> str_1 >> str_2;

        for (int i = 0, a = 0, b = 0; i < str_1.size() + str_2.size(); ++i)
        {
            if (b == str_2.size() || i % 2 == 0 && a < str_1.size())
                result.push_back(str_1[a++]);
            else
                result.push_back(str_2[b++]);
        }

        printf("%s\n", result.c_str());
    }
}
