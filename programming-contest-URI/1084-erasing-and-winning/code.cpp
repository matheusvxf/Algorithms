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
#include <string>

using namespace std;

#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)

struct compare
{
    bool operator()(const pair< char, int >& a, const pair< char, int >& b) const
    {
        return a.second < b.second;
    }
};

int main() {
    int N, D;

    while (cin >> N >> D && (N != 0 || D != 0))
    {
        string str, result;
        int removed = 0;
        int i;

        cin >> str;
        
        result.push_back(str[0]);
        for (i = 1; i < str.size(); ++i)
        {
            result.push_back(str[i]);
            
            if (removed < D)
            {
                int index = result.size() - 2;
                while (index >= 0 && removed < D && result[index] < result[index + 1])
                {
                    char tmp = result.back();
                    result.pop_back();
                    result.pop_back();
                    result.push_back(tmp);
                    removed++;
                    index--;
                }
            }
        }

        while (removed < D)
        {
            result.pop_back();
            removed++;
        }

        cout << result << endl;
    }
}
