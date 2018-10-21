#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

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
    
    void unite(int x, int y){
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

#define N 100
double x[N], y[N], z[N], r[N];

struct Edge{
    int from, to;
    double dist;
    Edge() {}
    Edge(int f, int t, double d) : from(f), to(t), dist(d) {}
    bool operator<(const Edge other) const{
        return dist < other.dist;
    }
};

double getDist(int i, int j){
    return sqrt(pow(x[j]-x[i], 2.0) + pow(y[j]-y[i], 2.0) + pow(z[j]-z[i], 2.0));
}

int main(){
    int n;
    while(cin >> n, n){
        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i] >> z[i] >> r[i];
        }

        DisjointSet uf(n);
        vector<Edge> res;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                double d = getDist(i,j);
                if(d > r[i]+r[j])    res.push_back(Edge(i,j,d-r[i]-r[j]));
                else                 uf.unite(i,j);
            }
        }

        sort(res.begin(), res.end());

        double ans = 0;
        for(int i = 0; i < res.size(); i++){
            if(!uf.same(res[i].from, res[i].to)){
                uf.unite(res[i].from, res[i].to);
                ans += res[i].dist;
            }
        }

        cout << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}