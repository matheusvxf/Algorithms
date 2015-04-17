#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double X;

    cin >> X;
    cout << fixed;
    for(register uint i = 0; i < 100; ++i){
    	cout << setprecision(4) << "N[" << i << "] = " << X << endl;
    	X = X / 2.0;
    }
}
