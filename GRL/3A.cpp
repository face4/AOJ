#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<int> ord(100000), low(100000), v[100000], parent(100000);
vector<bool> vis(100000, 0);
int rootCnt = 0;

void dfs(int x, int p, int &k){
    parent[x] = p;
    ord[x] = low[x] = k++;
    vis[x] = true;
    for(int j : v[x]){
        if(vis[j]){
            if(j != p)  low[x] = min(low[x], ord[j]);
        }else{
            if(x == 0)  rootCnt++;
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
    set<int> s;
    if(rootCnt > 1) s.insert(0);
    for(int i = 1; i < n; i++){
        int p = parent[i];
        if(p > 0 && low[i] >= ord[p])    s.insert(p);
    }
    for(int x : s)  cout << x << endl;
    return 0;
}