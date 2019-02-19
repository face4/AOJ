// 座標圧縮+2次元累積和(imos)
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cstring>
using namespace std;
typedef long long ll;
const int INF = 1e9+1;

vector<int> compress(vector<int> x, vector<int> y){
    vector<int> v;
    v.push_back(INF);
    v.push_back(-INF);
    for(auto i : x) v.push_back(i);
    for(auto i : y) v.push_back(i);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

// N = 2000,座圧で最大2000 * 2(両端)
int imos[4010][4010] = {};

int main(){
    int n;
    cin >> n;
    vector<int> x1(n), y1(n), x2(n), y2(n);
    for(int i = 0; i < n; i++)  cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    vector<int> x = compress(x1, x2);
    int h = x.size();
    vector<int> y = compress(y1, y2);
    int w = y.size();
    auto fx = [&](int val) -> int{
        return lower_bound(x.begin(), x.end(), val)-x.begin();
    };
    auto fy = [&](int val) -> int{
        return lower_bound(y.begin(), y.end(), val)-y.begin();
    };
    for(int i = 0; i < n; i++){
        int a = fx(x1[i]), b = fy(y1[i]), c = fx(x2[i])-1, d = fy(y2[i])-1;
        imos[a][b]++; imos[c+1][d+1]++;
        imos[a][d+1]--; imos[c+1][b]--;
    }
    ll ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(i)   imos[i][j] += imos[i-1][j];
            if(j)   imos[i][j] += imos[i][j-1];
            if(i != 0 && j != 0)    imos[i][j] -= imos[i-1][j-1];
            if(imos[i][j] > 0){
                ans += (ll)(x[i+1]-x[i])*(y[j+1]-y[j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}