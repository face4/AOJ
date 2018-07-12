// kruskal法
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;

class DisjointSet{
  public:
    vector<int> rank, p;

    DisjointSet(){}
    DisjointSet(int size){
        rank.resize(size, 0);
        p.resize(size, 0);
        for(int i = 0; i < size; i++) makeSet(i);
    }

    void makeSet(int x){
        p[x] = x;
        rank[x] = 0;
    }

    bool same(int x, int y){
        return findSet(x) == findSet(y);
    }
    
    bool unite(int x, int y){
        link(findSet(x), findSet(y));
    }

    void link(int x, int y){
        if(rank[x] > rank[y]){
            p[y] = x;
        }else{
            p[x] = y;
            if(rank[x] == rank[y]){
                rank[y]++;
            }
        }
    }

    int findSet(int x){
        if(x != p[x]){
            // path compression
            p[x] = findSet(p[x]);
        }
        return p[x];
    }
};

struct bridge{
    int from, to, cost;
    bridge(int f, int t, int c) : from(f), to(t), cost(c) {}
    bool operator<(const bridge other) const{
        return cost < other.cost;
    }
};

int main(){
    while(1){
        cin >> n >> m;
        if(n+m == 0)  break;

        DisjointSet uf(n);
        int a, b, c;
        vector<bridge> vb; 
        for(int i = 0; i < m; i++){
            cin >> a >> b >> c;
            vb.push_back(bridge(a,b,c));
        }

        sort(vb.begin(), vb.end());

        int ans = 0;
        for(bridge b : vb){
            if(uf.same(b.from, b.to))   continue;

            ans += b.cost;
            uf.unite(b.from, b.to);
        }

        cout << ans << endl;
    }
    return 0;
}