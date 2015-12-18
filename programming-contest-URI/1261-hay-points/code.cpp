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
    int M, N;
    map< string, int > dic;
    string str;
    stringstream buffer;

    scanf("%d %d\n", &M, &N);

    for (int i = 0; i < M; ++i)
    {
        int value;
        cin >> str >> value;
        dic[str] = value;
    }

    getline(cin, str);
    for (int i = 0; i < N; ++i)
    {
        long long int salary = 0;

        while (getline(cin, str) && str != ".")
        {
            buffer.clear();
            buffer.str(str);

            while (buffer >> str)
            {
                auto it = dic.find(str);
                if (it != dic.end())
                    salary += it->second;
            }
            
        }
        printf("%lld\n", salary);
    }
}
