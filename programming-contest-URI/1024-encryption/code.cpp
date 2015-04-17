#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>

using namespace std;

#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)
#define all(Q) Q.begin(), Q.end()

int main() {
    int T;
    string str;
    
    cin >> T;
    getline(cin, str);
    while (T--)
    {
        getline(cin, str);
        for (int i = 0; i < str.size(); ++i)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            {
                str[i] += 3;
            }
        }

        reverse(all(str));
        for (int i = str.size() / 2; i < str.size(); ++i)
        {
            str[i]--;
        }

        printf("%s\n", str.c_str());
    }
}
