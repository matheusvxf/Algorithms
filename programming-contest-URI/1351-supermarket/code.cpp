#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <deque>

using namespace std;

#define INF 1e10
#define all(Q) Q.begin(), Q.end()
#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)

class Shopping
{
public:
    vector< int > shopping_list;
    vector< pair< int, float > > supermarket;
    unordered_map< int, vector< int > > position;
    
    Shopping(int shopping_list_size, int supermarket_size) : shopping_list(shopping_list_size),
        supermarket(supermarket_size)
    {
    }

    inline float Cost(int position) { return supermarket[position].second; }
    inline int First(int item) { return position[item][0]; }
    inline int Last(int item) { return position[item].back(); }
    inline int Index(int item, unsigned int offset) {
        if (offset < position[item].size())
            return position[item][offset];
        else
            return -1;
    }

    int Find(vector< int >& S, int n)
    {
        int lower_bound = 0;
        int upper_bound = S.size() - 1;

        while (lower_bound <= upper_bound)
        {
            int avr = (lower_bound + upper_bound) / 2;

            if (S[avr] == n)
                return avr;
            if (lower_bound == upper_bound && S[avr] > n)
                return lower_bound;

            if (S[avr] < n)
            {
                lower_bound = avr + 1;
            }
            else
            {
                upper_bound = avr;
            }
        }

        return lower_bound;
    }

    float DynamicShopping()
    {
        int shopping_list_size = shopping_list.size();
        int supermarket_size = supermarket.size();
        vector< vector< float > > m(shopping_list_size);
        int last_item = shopping_list.back();
        int last_item_index = shopping_list.size() - 1;
        float tmp = INF;

        for (int i = 0; i < shopping_list_size; ++i)
        {
            m[i].resize(position[shopping_list[i]].size());
            fill(all(m[i]), -1.0f);
        }

        for(int i = position[last_item].size() - 1; i >= 0; --i)
        {
            tmp = std::min(tmp, Cost(position[last_item][i]));
            m[last_item_index][i] = tmp;
        }

        for (int i = shopping_list_size - 2; i >= 0; --i)
        {
            int item = shopping_list[i];
            int next_item = shopping_list[i + 1];

            for (int j = position[item].size() - 1; j >= 0; --j)
            {
                int pos = position[item][j];
                int next_item_index = Find(position[next_item], pos + 1);

                if (next_item_index < position[next_item].size() && next_item_index < m[i + 1].size())
                {
                    if (j + 1 < m[i].size())
                    {
                        if (m[i][j + 1] >= 0)
                            m[i][j] = min(m[i][j + 1], m[i + 1][next_item_index] + Cost(pos));
                        else if (m[i + 1][next_item_index] >= 0)
                            m[i][j] = m[i + 1][next_item_index] + Cost(pos);
                    }
                    else if(m[i + 1][next_item_index] >= 0)
                        m[i][j] = m[i + 1][next_item_index] + Cost(pos);
                }
                else
                {
                    if (j + 1 < m[i].size())
                        m[i][j] = m[i][j + 1];
                }
            }
        }

        return m[0].size() > 0 ? m[0][0] : -1;
    }
};

int main() {
    int M, N;

    while (scanf("%d %d\n", &M, &N) && M != 0)
    {
        Shopping shopping(M, N);
        float total = 0;

        for (int i = 0; i < M; ++i)
        {
            scanf("%d", &shopping.shopping_list[i]);
        }

        for (int i = 0; i < N; ++i)
        {
            int item;
            float price;

            scanf("%d %f\n", &item, &price);
            shopping.supermarket[i] = make_pair(item, price);
            shopping.position[item].push_back(i);
        }

        total = shopping.DynamicShopping();

        if (total != -1)
        {
            printf("%.2f\n", total);
        }
        else
        {
            printf("Impossible\n");
        }
    }
}
