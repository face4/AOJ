#include<iostream>
#include<iomanip>
#include<algorithm> // inplace_merge
#include<cmath>
#include<vector>
using namespace std;

typedef pair<double,double> p;
p v[100000];

const double INF = 1e10;

bool comp_y(p a, p b){
    return a.second < b.second;
}

// 分割統治 O(nlogn)
double closest_pair(p *a, int n){
    if(n <= 1)  return INF;
    
    int m = n/2;
    double x = a[m].first;
    double d = min(closest_pair(a, m), closest_pair(a+m, n-m)); // x軸で区切られた範囲内での頂点対のみ考慮
    inplace_merge(a, a+m, a+n, comp_y); // ソート済みの[a, a+m)と[a+m, a+n)をy座標基準でマージ

    vector<p> b; // 直線 x = a[m].firstから距離d未満の点を入れる
    for(int i = 0; i < n; i++){
        if(fabs(a[i].first-x) >= d) continue; // そもそもx座標の差がd以上の点は論外

        // bに入っている頂点を末尾から、y座標の差がd以上になるまで見ていく
        // y座標降順で見ていき、d以上離れた時点で打ち切り
        for(int j = 0; j < b.size(); j++){
            double dx = a[i].first - b[b.size()-1-j].first;
            double dy = a[i].second - b[b.size()-1-j].second;
            if(dy >= d) break;
            d = min(d, sqrt(dx*dx + dy*dy));
        }

        b.push_back(a[i]);
    }
    return d;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        double x, y;
        cin >> x >> y;
        v[i] = {x,y};
    }
    sort(v, v+n);
    cout << fixed << setprecision(12) << closest_pair(v, n) << endl;
    return 0;
}
