#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    int s = 1, i, g, empate, inter, gremio, counter;
    empate = inter = gremio = counter = 0;
    
    while(s == 1) {
        cin >> i >> g;
        counter++;
        cout << "Novo grenal (1-sim 2-nao)" << endl;

        if(i > g)
            inter++;
        else if(i < g)
            gremio++;
        else
            empate++;

        cin >> s;
    }

    cout << counter << " grenais" << endl;
    cout << "Inter:" << inter << endl;
    cout << "Gremio:" << gremio << endl;
    cout << "Empates:" << empate << endl;
    cout << (inter > gremio ? "Inter" : "Gremio") << " venceu mais" << endl;
}
