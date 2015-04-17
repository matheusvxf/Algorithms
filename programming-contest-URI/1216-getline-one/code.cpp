#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    double sum = 0;
    int counter = 0;
    char c;

    while ((c = getchar()) != EOF)
    {
        while (c != '\n') c = getchar();
        scanf("%d\n", &n);
        sum += n;
        counter++;
    }

    cout << setprecision(1) << fixed << sum / counter << endl;
}
