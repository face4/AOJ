#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> v[252], rev[252];
vector<bool> goal(252), way(252);

void abletogoal(int i){
    goal[i] = true;
    for(int next : rev[i]){
        if(!goal[next]) abletogoal(next);
    }
}

bool f(int i){
    bool ret = true;
    way[i] = true;
    ret &= goal[i];
    for(int next : v[i]){
        if(way[next])   continue;
        ret &= f(next);
    }
    return ret;
}

int main(){
    int m;
    while(cin >> m, m){
        for(int i = 0; i < 252; i++){
            v[i].clear(), rev[i].clear();
            goal[i] = way[i] = false;
        }

        int n;
        cin >> n;
        vector<int> d(n+2);
        for(int i = 1; i <= n; i++) cin >> d[i];
        for(int i = 0; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int ni = i+j;
                if(ni > n+1)    ni = n+1;
                else            ni += d[ni];
                if(ni > n+1)    ni = n+1;
                if(ni < 0)  ni = 0;
                v[i].push_back(ni);
                rev[ni].push_back(i);
            }
        }
        abletogoal(n+1);
        cout << (f(0) ? "OK" : "NG") << endl;
    }
    return 0;
}