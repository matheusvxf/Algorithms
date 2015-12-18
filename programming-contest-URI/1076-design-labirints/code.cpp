#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int main() {
    int T;

    cin >> T;

    while (T--)
    {
        int N, V, A;
        set< pair< int, int > > S;

        cin >> N;
        cin >> V >> A;

        for (int i = 0; i < A; ++i)
        {
            int x, y, tmp;
            
            cin >> x >> y;
            tmp = x;
            x = min(tmp, y);
            y = max(tmp, y);

            S.insert(make_pair(x, y));
        }

        cout << 2 * S.size() << endl;
    }
}
