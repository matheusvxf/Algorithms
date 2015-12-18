#include <iostream>
#include <deque>
#include <string.h>
#include <stdio.h>

using namespace std;

long long int mod = 1000000009;

int main() {
    int Q, D, P; 

    while(scanf("%d", &Q) && scanf("%d %d\n", &D, &P) != EOF) {
        int y = D * P * Q / (P - Q);

    	printf("%d %s\n", y, (y == 1 ? "pagina" : "paginas"));
    }
}
