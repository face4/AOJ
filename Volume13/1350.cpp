#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 簡易UF
struct UF{
    vector<int> p;
    int n;

    UF(int siz){
        n = siz;
        p.resize(n, 0);
        for(int i = 0; i < n; i++)  p[i] = i;
    }

    bool same(int x, int y){
        return parent(x) == parent(y);
    }

    int parent(int x){
        if(p[x] != x)   p[x] = parent(p[x]);
        return p[x];
    }

    void unite(int x, int y){
        x = parent(x), y = parent(y);
        p[x] = y;
    }
};

struct data{
    int cost, i, j;
    data(int a, int c, int d) : cost(a), i(c), j(d) {};
    bool operator< (const data other){
        return cost < other.cost;
    }
};

// O(N * M) 速いはず

int main(){
    int n, m;
    cin >> n >> m;

    vector<data> v;
    int s, d, c;
    
    for(int i = 0; i < m; i++){
        cin >> s >> d >> c;
        s--, d--;
        v.push_back(data({c,s,d}));
    }
    sort(v.begin(), v.end());

    int sptCost = 0, ans = 0, anssum = 0;
    vector<int> cand;
    UF uf(n);
    for(int x = 0; x < m; x++){
        int cost = v[x].cost, i = v[x].i, j = v[x].j;
        if(uf.same(i,j))    continue;
        sptCost += cost;
        cand.push_back(x);
        uf.unite(i,j);
    }

    for(int ng : cand){
        UF tmp(n);
        int tmpc = 0, edge = 0;
        for(int x = 0; x < m; x++){
            int cost = v[x].cost, i = v[x].i, j = v[x].j;
            if(ng == x || tmp.same(i,j))    continue;
            edge++;
            tmpc += cost;
            tmp.unite(i,j);
        }
        if(edge != n-1 || tmpc > sptCost)  ans++, anssum += v[ng].cost;
    }

    cout << ans << " " << anssum << endl;

    return 0;
}