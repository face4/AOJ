#include<iostream>
#include<vector>
using namespace std;

struct UnionFind{
    vector<int> p;
    int n;
    UnionFind(int s) : n(s){
        p.resize(n);
        for(int i = 0; i < n; i++)  p[i] = i;
    }

    int findSet(int x){
        if(p[x] != x){
            p[x] = findSet(p[x]);
        }
        return p[x];
    }

    void unite(int x, int y){
        x = findSet(x), y = findSet(y);
        if(x == y)  return;
        p[x] = y;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    int a, b;
    while(m-- > 0){
        cin >> a >> b;
        uf.unite(--a, --b);
    }
    int cnt[1000] = {};
    for(int i = 0; i < n; i++)  cnt[uf.findSet(i)]++;
    int ans = 0;
    for(int i = 0; i < n; i++)  ans += (cnt[i]>0)*(2*(cnt[i]>1)-1);
    cout << abs(ans) << endl;
    return 0;
}