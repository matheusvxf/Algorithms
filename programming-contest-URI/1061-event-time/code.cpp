#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(){
    int b_d, e_d, b_h, e_h, b_m, e_m, b_s, e_s;
    int d_d, d_h, d_m, d_s;
    
    scanf("Dia %d\n", &b_d);
    scanf("%d : %d : %d\n", &b_h, &b_m, &b_s);
    scanf("Dia %d\n", &e_d);
    scanf("%d : %d : %d\n", &e_h, &e_m, &e_s);
    
    d_s = e_s - b_s;
    d_m = e_m - b_m;
    d_h = e_h - b_h;
    d_d = e_d - b_d;
    
    if(d_s < 0){
        d_m--;
        d_s += 60;
    }
    if(d_m < 0){
        d_h--;
        d_m += 60;
    }
    if(d_h < 0){
        d_d--;
        d_h += 24;
    }
    
    printf("%d dia(s)\n", d_d);
    printf("%d hora(s)\n", d_h);
    printf("%d minuto(s)\n", d_m);
    printf("%d segundo(s)\n", d_s);
}
