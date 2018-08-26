#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

struct data{
    int v, w;
    ll d;
    string t, n;
    data(int _v, int _w, string _t, ll _d, string _n) 
    : v(_v), w(_w), t(_t), d(_d), n(_n) {}

    bool operator < (const data other) const{
        if(v != other.v)    return v < other.v;
        if(w != other.w)    return w < other.w;
        if(t != other.t)    return t < other.t;
        if(d != other.d)    return d < other.d;
        return n < other.n;
    }
};

int main(){
    int n;
    cin >> n;

    vector<data> v;
    int a, b;
    string c, e;
    ll d;

    for(int i = 0; i < n; i++){
        cin >> a >> b >> c >> d >> e;
        v.push_back(data(a, b, c, d, e));
    }

    sort(v.begin(), v.end());

    for(data x : v){
        cout << x.v << " " << x.w << " " << x.t << " " << x.d << " " << x.n << endl;
    }

    return 0;
}