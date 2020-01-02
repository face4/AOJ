#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> ord(100000), low(100000), v[100000];
vector<bool> vis(100000, 0);

void dfs(int x, int p, int &k){
    ord[x] = low[x] = k++;
    vis[x] = true;
    for(int j : v[x]){
        if(vis[j]){
            if(j != p)  low[x] = min(low[x], ord[j]);
        }else{
            dfs(j, x, k);
            low[x] = min(low[x], low[j]);
        }
    }
}

typedef pair<int,int> pii;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pii> vp;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        if(a > b)   swap(a, b);
        vp.push_back({a, b});
    }
    int k = 0;
    dfs(0, -1, k);
    sort(vp.begin(), vp.end());
    vector<pii> ret;
    for(pii p : vp){
        int x = p.first, y = p.second;
        if(ord[x] > ord[y]) swap(x, y);
        if(ord[x] < low[y]) ret.push_back(p);
    }
    for(pii p : ret)    cout << p.first << " " << p.second << endl;
    return 0;
}