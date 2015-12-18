#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <sstream>
#include <string.h>

using namespace std;

int main(){
    int N, kg;
    float V, total_kg, spent;
    stringstream buffer;
    string tmp, str;

    total_kg = spent = 0;

    cin >> N;

    for(register uint day = 0; day < N; ++day) {
        kg = 0;
        buffer.clear();

        cin >> V;
        getline(cin, str);
        getline(cin, str);
        buffer.str(str);
        
        while(buffer >> tmp)
            kg++;

        spent += V;
        total_kg += kg;

        cout << "day " << day + 1 << ": " << kg << " kg" << endl;
    }

    cout << fixed;
    cout << setprecision(2) << total_kg / (float)N << " kg by day" << endl;
    cout << setprecision(2) << "R$ " << spent / (float)N << " by day" << endl;
}
