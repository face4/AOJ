#include<iostream>
#include<queue>
#include<set>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
char dir[4] = {'u', 'r', 'd', 'l'};

int limit;  // 深さの制限
int path[100];  // 操作の履歴

// manhattan distance
int md[16][16];

struct Puzzle{
    int a[16], emp, mdsum, cost;
    bool operator< (const Puzzle &other) const{
        for(int i = 0; i < 16; i++){
            if(a[i] == other.a[i])  continue;
            return a[i] < other.a[i];
        }
        return false;
    }
};

Puzzle state;

bool isSolved(Puzzle &x){
    for(int i = 0; i < 16; i++) if(i+1 != x.a[i])   return false;
    return true;
}

int calcMd(Puzzle &x){
    int ret = 0;
    for(int i = 0; i < 16; i++){
        if(x.a[i] == 16)    continue;
        ret += md[i][x.a[i]-1];
    }
    return ret;
}

bool dfs(int depth, int prev){
    if(state.mdsum == 0)    return true;
    if(depth + state.mdsum > limit) return false;

    int i = state.emp/4, j = state.emp%4;
    Puzzle tmp;
    for(int r = 0; r < 4; r++){
        if(abs(r-prev) == 2)    continue;
        int ni = i+di[r], nj = j+dj[r];
        if(!inRange(ni,0,4) || !inRange(nj,0,4))    continue;
        tmp = state;
        int val = state.a[ni*4+nj]-1;
        state.mdsum -= md[ni*4+nj][val];
        state.mdsum += md[i*4+j][val];
        swap(state.a[i*4+j], state.a[ni*4+nj]);
        state.emp = ni*4+nj;
        if(dfs(depth+1, r)){
            path[depth] = r;
            return true;
        }
        state = tmp;
    }
    return false;
}

string iterative_deepening(Puzzle in){
    in.mdsum = calcMd(in);
    for(limit = in.mdsum; limit <= 100; limit++){
        state = in;
        if(dfs(0, -100)){
            string ans = "";
            for(int i = 0; i < limit; i++)  ans += dir[path[i]];
            return ans;
        }
    }
    return "unsolvable";
}

struct State{
    Puzzle puzzle;
    int est;
    bool operator < (const State &other) const{
        return est > other.est;
    }
};

int astar(Puzzle s){
    priority_queue<State> pq;
    s.mdsum = calcMd(s);
    s.cost = 0;
    set<Puzzle> memo;
    State init;
    init.puzzle = s;
    init.est = s.mdsum;
    pq.push(init);
    while(!pq.empty()){
        auto p = pq.top();  pq.pop();
        Puzzle u = p.puzzle;
        if(u.mdsum == 0)    return u.cost;
        memo.insert(u);
        int i = u.emp/4, j = u.emp%4;
        for(int r = 0; r < 4; r++){
            int ni = i+di[r], nj = j+dj[r];
            if(!inRange(ni,0,4) || !inRange(nj,0,4))    continue;
            Puzzle v = u;
            int val = u.a[ni*4+nj]-1;
            v.mdsum -= md[ni*4+nj][val];
            v.mdsum += md[i*4+j][val];
            swap(v.a[i*4+j], v.a[ni*4+nj]);
            v.emp = ni*4+nj;
            if(memo.count(v) == 0){
                v.cost++;
                State news;
                news.puzzle = v;
                news.est = v.cost + v.mdsum;
                pq.push(news);
            }
        }
    }
    return -1;
}


int main(){
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            md[i][j] = abs(i/4-j/4) + abs(i%4-j%4);
        }
    }
    Puzzle in;
    for(int i = 0; i < 16; i++){
        cin >> in.a[i];
        if(in.a[i] == 0){
            in.a[i] = 16;
            in.emp = i;
        }
    }
    string ans = iterative_deepening(in);
    cout << ans.size() << endl;
    // cout << astar(in) << endl;
    return 0;
}