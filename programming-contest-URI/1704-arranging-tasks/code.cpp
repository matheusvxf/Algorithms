#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define DEBUG 0

struct job{
    int v;
    int t;
};

bool latter_deadline_bigger_value_first (const job& a, const job& b) {
    if(a.t == b.t){
        return a.v > b.v;
    } else {
        return a.t > b.t;
    }
}

struct bigger_value_first {
    bool operator() (const job* a, const job* b) const {
        return a->v > b->v;
    }
};

struct lower_value_first {
    bool operator() (const job& a, const job& b) const {
        return a.v < b.v;
    }
};

void job_selection(job *p_job, int N, int H, int lost)
{
    multiset<job*, bigger_value_first> feasible;
    job *j;
    int slot, i = 0;
    
    while(i < N || (feasible.size() != 0 && slot >= 0)) {
        if(feasible.size() == 0)
            slot = p_job[i].t - 1;
        
        while(i < N && p_job[i].t > slot) {
            feasible.insert(&p_job[i++]);
        }
        
        j = *feasible.begin();
        lost -= j->v;
        feasible.erase(feasible.begin());
        
        slot--;
    }
    
    cout << lost << endl;
}

int main(){
    int N, H, lost;
    job *p_job;
    
    while(cin >> N >> H){
        p_job = new job[N];
        lost = 0;
        
        for(register int i = 0; i < N; ++i){
            cin >> p_job[i].v >> p_job[i].t;
            lost += p_job[i].v;
        }
        
        sort(p_job, p_job + N, latter_deadline_bigger_value_first);
        
        job_selection(p_job, N, H, lost);
        
        delete[]p_job;
    }
}
