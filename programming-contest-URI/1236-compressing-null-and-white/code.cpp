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
        char c;
        char str[3000], compressed[3000];
        int white_space = 0, zero = 0;
        int i = 0, j = 0, k = 0;

        memset(str, 0, 3000);
        memset(compressed, 0, 3000);
        while (scanf("%c", &c) && c != '\n')
            str[i++] = c;

        i = 0;
        while (str[i] != 0)
        {
            if (str[i] == ' ')
            {
                j = i + 1;
                while (j - i < 255 && str[j++] != 0 && str[j] == ' ');
                if (j - i > 2)
                {
                    compressed[k++] = '$';
                    compressed[k++] = (j - i);
                    i = j;
                }
                else
                    while (i < j) compressed[k++] = str[i++];
            }
            else if (str[i] == '0')
            {
                j = i + 1;
                while (j - i < 255 && str[j++] != 0 && str[j] == '0');
                if (j - i > 2)
                {
                    compressed[k++] = '#';
                    compressed[k++] = (j - i);
                    i = j;
                }
                else
                {
                    while (i < j) compressed[k++] = str[i++];
                }
            }
            else
            {
                compressed[k++] = str[i++];
            }
        }

        printf("%s\n", compressed);
    }
}
