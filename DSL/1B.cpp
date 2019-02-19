#include<iostream>
#include<vector>
using namespace std;

// https://qiita.com/drken/items/cce6fc5c579051e64fab
struct WeightedUnionFind{
    vector<int> par;
    vector<int> rank;
    vector<int> diff;

    WeightedUnionFind(int n){
        init(n);
    }

    void init(int n){
        par.resize(n); rank.resize(n, 0); diff.resize(n, 0);
        for(int i = 0; i < n; i++)  par[i] = i;
    }

    int root(int x){
        if(par[x] == x){
            return x;
        }else{
            int r = root(par[x]);
            diff[x] += diff[par[x]];
            return par[x] = r;
        }
    }

    // 単ノードの重み取得
    int weight(int x){
        root(x);
        return diff[x];
    }

    int dif(int x, int y){
        return weight(y) - weight(x);
    }

    bool isSame(int x, int y){
        return root(x) == root(y);
    }

    // weight(y) - weight(x) = w となるように merge
    bool merge(int x, int y, int w){
        // x が y の親になることを考えると、更新の起点はdiff[y]で、
        // diff[y] を w + weight(x) - weight(y) にすればよい
        // 感覚としては、新しいdiff[y]を a と置いたときに、
        // a = w - weight(y) - (-weight[x]) とするイメージが強い
        w += weight(x); w -= weight(y);

        x = root(x); y = root(y);
        if(x == y)  return false;
        if(rank[x] < rank[y])   swap(x, y), w = -w;
        if(rank[x] == rank[y])  rank[x]++;
        par[y] = x;
        diff[y] = w;
        return true;
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    WeightedUnionFind uf(n);
    while(q-- > 0){
        int a, b, c, d;
        cin >> a >> b >> c;
        if(a == 0){
            cin >> d;
            uf.merge(b, c, d);
        }else{
            if(uf.isSame(b, c)) cout << uf.dif(b, c) << endl;
            else                cout << "?" << endl;
        }
    }
    return 0;
}