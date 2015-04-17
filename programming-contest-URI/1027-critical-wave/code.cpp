#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

#define foreach(Q, it) for(auto it = Q.begin(); it != Q.end(); ++it)
#define all(Q) Q.begin(), Q.end()
#define LOW 0
#define HIGH 1

int BinarySearch(vector< pair< int, int > > &P,
    map< pair< int, int >, int >& point_to_index, int x)
{
    int lower_bound = 0, upper_bound = P.size() - 1;

    while (lower_bound <= upper_bound)
    {
        int avr = (lower_bound + upper_bound) / 2;

        if (P[avr].first == x)
            return point_to_index[P[avr]];

        if (lower_bound == upper_bound && P[avr].first >= x)
            return point_to_index[P[avr]];

        if (P[avr].first < x)
        {
            lower_bound = avr + 1;
        }
        else
        {
            upper_bound = avr;
        }
    }

    if (lower_bound < P.size())
        return point_to_index[P[lower_bound]];
    else
        return -1;
}

int CritivalWave(unordered_map< int, vector< pair< int, int > > >& P, vector< pair< int, int > >& points, map< pair< int, int >, int >& point_to_index)
{
    int num_points = points.size();
    vector< vector< int > > m(num_points);
    int last = num_points - 1;
    int maximum = 0;

    for (int i = 0; i < num_points; ++i)
    {
        m[i].resize(2);
        fill(all(m[i]), 1);
    }

    for (int i = last - 1; i >= 0; --i)
    {
        int x = points[i].first;
        int y = points[i].second;
        vector< pair< int, int > > *H = &P[y];
        vector< pair< int, int > > *H_plus_2 = &P[y + 2];
        vector< pair< int, int > > *H_minus_2 = &P[y - 2];
        int next_point_y = BinarySearch(*H, point_to_index, x + 1);
        int next_point_y_plus_2 = BinarySearch(*H_plus_2, point_to_index, x + 1);
        int next_point_y_minus_2 = BinarySearch(*H_minus_2, point_to_index, x + 1);

        if (next_point_y >= 0 && next_point_y < num_points)
        {
            if (next_point_y_plus_2 >= 0 && next_point_y_plus_2 < num_points)
                m[i][LOW] = max(m[next_point_y][LOW], m[next_point_y_plus_2][HIGH] + 1);
            else
                m[i][LOW] = m[next_point_y][LOW];

            if (next_point_y_minus_2 >= 0 && next_point_y_minus_2 < num_points)
                m[i][HIGH] = max(m[next_point_y][HIGH], m[next_point_y_minus_2][LOW] + 1);
            else
                m[i][HIGH] = m[next_point_y][HIGH];
        }
        else
        {
            if (next_point_y_plus_2 >= 0 && next_point_y_plus_2 < num_points)
                m[i][LOW] = m[next_point_y_plus_2][HIGH] + 1;

            if (next_point_y_minus_2 >= 0 && next_point_y_minus_2 < num_points)
                m[i][HIGH] = m[next_point_y_minus_2][LOW] + 1;
        }

        maximum = max(maximum, m[i][HIGH]);
        maximum = max(maximum, m[i][LOW]);
    }

    return maximum;
}

int main()
{
    int N;

    while (scanf("%d\n", &N) != EOF)
    {
        unordered_map< int, vector< pair< int, int > > > P;
        vector< pair< int, int > > points;
        map< pair< int, int >, int > point_to_index;
        int i = 0;

        for (int i = 0; i < N; ++i)
        {
            int x, y;
            scanf("%d %d\n", &x, &y);
            P[y].push_back(make_pair(x, y));
            points.push_back(make_pair(x, y));
        }

        foreach(P, it)
            sort(all(it->second));
        sort(all(points));
        i = 0;
        for (auto it = points.begin(); it != points.end(); ++it)
            point_to_index[make_pair(it->first, it->second)] = i++;

        printf("%d\n", CritivalWave(P, points, point_to_index));
    }
}
