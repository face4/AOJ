#include<iostream>
#include<vector>
using namespace std;

struct UnionFind{
    vector<int> p, rank, v, mark, d[100000];
    int n;
    UnionFind(int siz){
        n = siz;
        p.resize(n), rank.resize(n, 0), v.resize(n, 0), mark.resize(n, 0);
        mark[0]++;
        for(int i = 0; i < n; i++)  p[i] = i;
        for(int i = 1; i < n; i++)  cin >> v[i], v[i]--;
        for(int i = 1; i < n; i++)  d[v[i]].push_back(i);
        dfs(0, 0);
    }

    void dfs(int pos, int dep){
        rank[pos] = dep;
        for(int next : d[pos])  dfs(next, dep+1);
    }

    int findSet(int x){
        if(p[x] != x)   p[x] = findSet(p[x]);
        return p[x];
    }

    void unite(int x, int y){
        x = findSet(x), y = findSet(y);
        if(x == y)  return;
        if(rank[x] < rank[y]){
            p[y] = x;
        }else{
            p[x] = y;
        }
    }

    void dfs2(int pos){
        if(pos != 0 && mark[pos] == 0){
            unite(pos, v[pos]);
        }
        for(int next : d[pos]){
            dfs2(next);
        }
    }
};

typedef long long ll;

int main(){
    int n, q;
    while(cin >> n >> q, n+q){
        UnionFind uf(n);
        char op[q];
        int x[q];
        for(int i = 0; i < q; i++){
            cin >> op[i] >> x[i];
            x[i]--;
            if(op[i] == 'M')    uf.mark[x[i]]++;
        }
        uf.dfs2(0);
        ll ans = 0;
        for(int i = q-1; i >= 0; i--){
            if(op[i] == 'Q'){
                ans += uf.findSet(x[i])+1;
            }else{
                uf.mark[x[i]]--;
                if(uf.mark[x[i]])   continue;
                uf.unite(x[i], uf.v[x[i]]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}