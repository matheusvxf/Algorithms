#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

struct team{
    string name;
    int points;
    int wins;
    int goals;
    int id;
};

bool compare (const team& a, const team& b) {
    if(a.points > b.points)
        return true;
    else if(a.points < b.points)
        return false;
    else if(a.wins > b.wins)
        return true;
    else if(a.wins < b.wins)
        return false;
    else if(a.goals > b.goals)
        return true;
    else if(a.goals < b.goals)
        return false;
    else
        return a.id < b.id;
}

int main(){
    int T, N, M, x, y, i, j;
    string team_a, team_b;
    map< string, int > table;
    team *p_team;
    
    cin >> T;
    while(T-- > 0){
        cin >> N >> M;
        
        p_team = new team[N];
        
        for(register int i = 0; i < N; ++i) {
            cin >> p_team[i].name;\
            table[p_team[i].name] = i;
            p_team[i].points = p_team[i].wins = p_team[i].goals = 0;
            p_team[i].id = i;
        }
        
        for(register int k = 0; k < M; ++k) {
            cin >> x >> team_a >> y >> team_b;
            i = table[team_a];
            j = table[team_b];
            
            if(x > y) {
                p_team[i].points += 3;
                p_team[i].wins++;
            }
            else if(x < y) {
                p_team[j].points += 3;
                p_team[j].wins++;
            }
            else {
                p_team[i].points++;
                p_team[j].points++;
            }
            p_team[i].goals += x;
            p_team[j].goals += y;
        }
        
        sort(p_team, p_team + N, compare);
        
        for(register int i = 0; i < N; ++i) {
            cout << p_team[i].name << endl;
            /*cout << "points: " << p_team[i].points << endl;
            cout << "wins:" << p_team[i].wins << endl;
            cout << "goals: "<< p_team[i].goals << endl;
            cout << "id: " << p_team[i].id << endl;*/
        }
        
        delete[]p_team;
    }
}
