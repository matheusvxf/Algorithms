#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

#define all(Q) Q.begin(), Q.end()

void ParseTreePosOrder(string& pre_order, string &in_order)
{
    auto it = find(all(in_order), pre_order[0]);

    if (pre_order.size() == 0)
        return;

    int left_tree_size = it - in_order.begin();
    string left_in_order(in_order.begin(), it);
    string right_in_order(it + 1, in_order.end());
    string left_pre_order(pre_order.begin() + 1, pre_order.begin() + 1 + left_tree_size);
    string right_pre_order(pre_order.begin() + 1 + left_tree_size, pre_order.end());

    ParseTreePosOrder(left_pre_order, left_in_order);
    ParseTreePosOrder(right_pre_order, right_in_order);

    printf("%c", pre_order[0]);
}

int main() {
    int T;
	string a, b;

    cin >> T;

	while(T--) {
        int size;

        cin >> size;
        cin >> a >> b;
        ParseTreePosOrder(a, b);

        printf("\n");
	}
}
