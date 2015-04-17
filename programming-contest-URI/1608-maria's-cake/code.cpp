#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

struct team{
    string name;
    int points;
    int wins;
    int goals;
    int id;
};

int main(){
    int T, D, I, B, Q_i, index, amount, cake_cost, most_cake;
    int *price;
    string team_a, team_b;
    map< string, int > table;
    team *p_team;
    
    cin >> T;
    while(T-- > 0){
        cin >> D >> I >> B;
        price = new int[I];
        most_cake = 0;

        for(register uint i = 0 ; i < I; ++i)
            cin >> price[i];

        for(register uint i = 0; i < B; ++i){
            cin >> Q_i;
            cake_cost = 0;
            for(register uint j = 0; j < Q_i; ++j){
                cin >> index >> amount;
                cake_cost += price[index] * amount;
            }
            if(D / cake_cost > most_cake)
                most_cake = D / cake_cost;
        }

        cout << most_cake << endl;

        delete[]price;
    }
}
