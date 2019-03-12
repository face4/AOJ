#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int>> v[20];
int n;

void init(){
    for(int i = 0; i < 20; i++) v[i].clear();
}

int dfs(int now, int par){
    int ret = 0;
    for(pair<int,int> p : v[now]){
        if(p.first == par)  continue;
        if(v[p.first].size() != 1){
            ret += dfs(p.first, now) + 2*p.second;
        }
    }
    return ret;
}

int dfs2(int now, int par){
    int ret = 0;
    for(pair<int,int> p : v[now]){
        if(p.first == par)  continue;
        if(v[p.first].size() != 1){
            ret = max(ret, p.second+dfs2(p.first, now));
        }
    }
    return ret;
}

int main(){
    while(cin >> n, n){
        init();
        int a, b, t;
        for(int i = 0; i < n-1; i++){
            cin >> a >> b >> t;
            a--, b--;
            v[a].push_back({b,t});
            v[b].push_back({a,t});
        }
        cout << dfs(0,-1) - dfs2(0,-1) << endl;
    }
    return 0; 
}