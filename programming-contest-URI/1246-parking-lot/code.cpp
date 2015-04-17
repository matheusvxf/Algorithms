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

using namespace std;

#define all(Q) Q.begin(), Q.end()
#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)

class Spot
{
public:
    int position;
    int length;

    Spot() : Spot(-1, -1) {}
    Spot(int p, int l) : position(p), length(l) {}

    bool operator<(const Spot& a) const
    {
        return position < a.position;
    }
};

int main()
{
    int C, N;

    while (scanf("%d %d\n", &C, &N) != EOF)
    {
        set< Spot > spot_list;
        map< int, Spot > held_spot;
        int profit = 0;
        
        spot_list.insert(Spot(0, C));

        for (int i = 0; i < N; ++i)
        {
            int P, Q;
            char event_type;

            scanf("%c", &event_type);

            if (event_type == 'C')
            {
                scanf("%d %d\n", &P, &Q);

                foreach(spot_list, it)
                {
                    if (it->length >= Q)
                    {
                        held_spot[P] = Spot(it->position, Q);
                        if (it->length - Q > 0)
                            spot_list.insert(Spot(it->position + Q, it->length - Q));
                        spot_list.erase(it);
                        profit += 10;
                        break;
                    }
                }
            }
            else
            {
                scanf("%d\n", &P);
                spot_list.insert(held_spot[P]);
                auto it = spot_list.find(held_spot[P]);
                held_spot.erase(held_spot.find(P));

                if (it != spot_list.begin())
                {
                    auto previous = it; previous--;
                    auto next = it; next++;
                    Spot prev_spot = *previous;
                    Spot next_spot;

                    if (previous->position + previous->length == it->position)
                    {
                        spot_list.erase(previous);
                        prev_spot.length += it->length;
                        spot_list.insert(prev_spot);
                        spot_list.erase(it);
                        it = spot_list.find(prev_spot);
                    }
                    
                    next = it; next++;
                    if (next != spot_list.end() && it->position + it->length == next->position)
                    {
                        next_spot = *next;
                        spot_list.erase(next);
                        next_spot.length += it->length;
                        next_spot.position -= it->length;
                        spot_list.erase(it);
                        spot_list.insert(next_spot);
                    }
                }
                else
                {
                    auto next = it; next++;
                    Spot next_spot;
                    if (next != spot_list.end() && it->position + it->length == next->position)
                    {
                        next_spot = *next;
                        spot_list.erase(next);
                        next_spot.length += it->length;
                        next_spot.position -= it->length;
                        spot_list.erase(it);
                        spot_list.insert(next_spot);
                    }
                }
            }
        }

        printf("%d\n", profit);
    }
}