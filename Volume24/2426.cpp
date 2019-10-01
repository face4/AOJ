#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int INF = 1e9+1;
int v[5002][5002] = {};

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", x.begin()+i, y.begin()+i);
    }
    vector<int> ax = x, ay = y;
    ax.push_back(-INF); ax.push_back(INF);
    ay.push_back(-INF); ay.push_back(INF);
    sort(ax.begin(), ax.end());
    ax.erase(unique(ax.begin(),ax.end()),ax.end());
    sort(ay.begin(), ay.end());
    ay.erase(unique(ay.begin(),ay.end()),ay.end());
    int nx = ax.size(), ny = ay.size();
    auto fx = [&](int val)->int{
        return lower_bound(ax.begin(),ax.end(),val)-ax.begin();
    };
    auto fy = [&](int val)->int{
        return lower_bound(ay.begin(), ay.end(), val)-ay.begin();
    };
    for(int i = 0; i < n; i++){
        v[fx(x[i])][fy(y[i])]++;
    }
    for(int i = 0; i < nx; i++){
        for(int j = 1; j < ny; j++){
            v[i][j] += v[i][j-1];
        }
    }
    for(int j = 0; j < ny; j++){
        for(int i = 1; i < nx; i++){
            v[i][j] += v[i-1][j];
        }
    }
    auto get = [&](int lx, int rx, int ly, int ry)->int{
        return v[rx][ry]-v[rx][ly-1]-v[lx-1][ry]+v[lx-1][ly-1];
    };
    for(int i = 0; i < m; i++){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        cout << get(fx(a),fx(c+1)-1,fy(b),fy(d+1)-1) << endl;
    }
    return 0;
}
