#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <stdio.h>

using namespace std;

#define all(Q) Q.begin(), Q.end()

int main() {
    int T;

    scanf("%d\n", &T);

    while (T--)
    {
        string str;
        cin >> str;
        
        sort(all(str));

        do
        {
            printf("%s\n", str.c_str());
        } while (next_permutation(all(str)));

        printf("\n");
    }
}
