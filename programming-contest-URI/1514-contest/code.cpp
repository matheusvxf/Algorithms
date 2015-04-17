#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>
#include <string>
#include <string.h>

using namespace std;


#define all(Q) Q.begin(), Q.end()

int main() {
    int N, M;

    while (scanf("%d %d\n", &N, &M) && N != 0)
    {
        vector< vector < int > > matrix(N);
        vector< int > solved_by_at_least_one(M);
        vector< int > solved_by_everyone(M);
        int someone_solved_everything = 0;
        int everyone_solved_at_least_one = 1;
        int all_solved_by_at_least_one = 1;
        int problem_solved_by_everyone = 0;
        int caracteristics_achieved = 0;

        fill(all(solved_by_at_least_one), 0);
        fill(all(solved_by_everyone), 1);

        for (int i = 0; i < N; ++i)
        {
            int solved_everything = 1;
            int solved_at_least_one = 0;
            matrix[i].resize(M);

            for (int j = 0; j < M; ++j)
            {
                int bit;

                scanf("%d", &bit);
                matrix[i][j] = bit;
                solved_everything &= bit;
                solved_at_least_one |= bit;
                solved_by_at_least_one[j] |= bit;
                solved_by_everyone[j] &= bit;
            }

            someone_solved_everything |= solved_everything;
            everyone_solved_at_least_one &= solved_at_least_one;
        }

        for (int i = 0; i < M; ++i)
        {
            all_solved_by_at_least_one &= solved_by_at_least_one[i];
            problem_solved_by_everyone |= solved_by_everyone[i];
        }

        caracteristics_achieved += !someone_solved_everything + everyone_solved_at_least_one + all_solved_by_at_least_one + !problem_solved_by_everyone;

        printf("%d\n", caracteristics_achieved);
    }
}
