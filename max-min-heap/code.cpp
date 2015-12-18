#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <string>

using namespace std;

#define uint unsigned int
#define FIND(Q, q) (Q.find(q) != Q.end())
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)
#define INF ((int)10e6)
#define all(Q) Q.begin(), Q.end()
#define pi 3.14159

class Heap
{
public:
    vector< int > v;
    int last;

    Heap() : last(0)
    {

    }

    void Insert(int num)
    {
        int m = last;

        v.push_back(num);
        last++;

        while (m != 0)
        {
            int n = (m % 2 == 0 ? (m - 2) >> 1 : (m - 1) >> 1);

            if (Compare(v[m], v[n]))
            {
                int tmp = v[n];
                v[n] = v[m];
                v[m] = tmp;
            }
            else
            {
                break;
            }
            m = n;
        }

    }

    void Remove()
    {
        int n = 0;
        
        v[0] = v[last - 1];
        last--;

        while (n < last)
        {
            int m = n * 2 + 1;

            if (m >= last)
                break;
            if (m + 1 >= last)
            {
                if (Compare(v[m], v[n]))
                    swap(v[m], v[n]);
                break;
            }
            else
            {
                if (Compare(v[m], v[m + 1]))
                {
                    if (Compare(v[m], v[n]))
                    {
                        swap(v[m], v[n]);
                        n = m;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (Compare(v[m + 1], v[n]))
                    {
                        swap(v[m + 1], v[n]);
                        n = m + 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        v.pop_back();
    }

    int Front()
    {
        return v[0];
    }

    bool Empty()
    {
        return last == 0;
    }

    virtual bool Compare(int a, int b)
    {
        return a < b; // Min Heap
    }
};


int main() {
    int N;
    Heap H;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        H.Insert(a);
    }

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cout << H.Front() << endl;
        H.Remove();
    }

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        H.Insert(a);
    }

    while (!H.Empty())
    {
        cout << H.Front() << endl;
        H.Remove();
    }
}
