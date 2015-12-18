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
    string str;

    while (getline(cin, str))
    {
        bool to_lower = false;
        for_each(all(str), tolower);

        foreach(str, it)
        {
            if (to_lower)
            {
                printf("%c", tolower(*it));
            }
            else
            {
                printf("%c", toupper(*it));
            }
            if (*it != ' ')
                to_lower = !to_lower;
        }
        printf("\n");
    }
}
