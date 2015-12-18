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
    char N;

    while (scanf("%c ", &N) && N != '0')
    {
        char c;
        bool begin = true;

        while ((c = getchar()) && c != '\n')
        {
            if (c != N)
            {
                if (begin)
                {
                    if (c != '0')
                    {
                        begin = false;
                        printf("%c", c);
                    }
                }
                else
                {
                    printf("%c", c);
                }
            }
        }
        if (begin)
            printf("0");
        printf("\n");
    }
}
