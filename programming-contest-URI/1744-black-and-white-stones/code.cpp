#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cassert>
#include <unordered_map>
#include <string.h>
#include <stdio.h>
 
using namespace std;
 
#define uint unsigned int
#define INF 1e15
#define FIND(Q, q) (Q.find(q) != Q.end())
#define foreach(Q, it) for(auto it = (Q).begin(); it != (Q).end(); ++it)
#define all(Q) Q.begin(), Q.end()

class Solve
{
public:
    char *str;
    int len, n, A, C;
    long long int m[5000][5000];

    Solve()
    {
        for (int i = 0; i < 5000; ++i)
        for (int j = 0; j < 5000; ++j)
            m[i][j] = -1;
    }

    long long int DynamicStone(int i, int b)
    {
        if (m[i][b] != -1)
            return m[i][b];

        if (i == len - 1)
        {
            if (b == 0)
                return m[i][b] = 0;
            else if (str[i] == 'B' && b == 1)
                return m[i][b] = C * (b - 1);
            else
                return m[i][b] = INF;
        }
        if (i < n)
        {
            if (str[i] == 'B' && b == 0)
                return m[i][b] = DynamicStone(i + 1, b);
            else if (str[i] == 'B')
                return m[i][b] = C * (b - 1) + min(DynamicStone(i + 1, b) + C, DynamicStone(i + 1, b - 1) + A);
            else
                return m[i][b] = C * b + min(DynamicStone(i + 1, b + 1) + C, DynamicStone(i + 1, b) + A);
        }
        else
        {
            if (b == 0)
                return m[i][b] = 0;
            else if (str[i] == 'W')
                return m[i][b] = C * b + DynamicStone(i + 1, b);
            else
                return m[i][b] = C * (b - 1) + DynamicStone(i + 1, b - 1);
        }
    }

    long long int OPT()
    {
        int i = len - 1, b = 0;

        m[i][b++] = 0;
        if(str[i] == 'B')
            m[i][b++] = C * (b - 1);
        while (b < len)
            m[i][b++] = INF;

        i--;
        while (i >= n)
        {
            if (str[i] == 'W')
            for (b = 0; b < len; ++b)
                m[i][b] = C * b + m[i + 1][b];
            else
            {
                b = 0;
                m[i][b++] = m[i + 1][b];
                while (b < len)
                    m[i][b++] = C * (b - 1) + m[i + 1][b - 1];
            }
            i--;
        }

        while (i >= 0)
        {
            b = 0;
            if (str[i] == 'B')
                m[i][b++] = m[i + 1][b];
            else
                m[i][b++] = C * b + min(m[i + 1][b + 1] + C, m[i + 1][b] + A);
            while (b < len)
            { 
                if (str[i] == 'B')
                    m[i][b++] = C * (b - 1) + min(m[i + 1][b] + C, m[i + 1][b - 1] + A);
                else
                    m[i][b++] = C * b + min(m[i + 1][b + 1] + C, m[i + 1][b] + A);
            }
            i--;
        }
        return m[0][0];
    }
} solve;

int main()
{
    int A, B, C;
    char str[5001], c;
    int len, i = 0;
    long long int cost = 0;
    vector< int > index_w, index_b;

    scanf("%d %d\n", &A, &B);
    while (scanf("%c", &c) && c != '\n')
    {
        str[i++] = c;
        if (c == 'W')
            index_w.push_back(i - 1);
        else
            index_b.push_back(i - 1);
    }
    str[i] = 0;
    len = i;
    C = A - B;

    solve.str = str;
    solve.len = len;
    solve.n = index_b.size();
    solve.A = A;
    solve.C = C;
    cost = solve.DynamicStone(0, 0);

    printf("%lld\n", cost);
}
