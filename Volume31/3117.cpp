#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;

template<typename T>
struct Seg{
private:
    vector<T> node;
    int n;
    function<T(T,T)> f;
    T def;

public:
    Seg(int siz, T d, function<T(T,T)> f) : def(d), f(f) {
        n = 1;
        while(n < siz)  n *= 2;
        node.resize(2*n-1, def);
    }
    Seg(vector<T> v, T d, function<T(T,T)> f) : def(d), f(f){
        n = 1;
        while(n < v.size())  n *= 2;
        node.resize(2*n-1);
        for(int i = 0; i < v.size(); i++)   node[n-1+i] = v[i];
        for(int i = n-2; i >= 0; i--)   node[i] = f(node[2*i+1], node[2*i+2]);
    }

    void update(int x, T val){
        x += n-1;
        node[x] += val; /* ! */
        while(x){
            x = (x-1)/2;
            node[x] = f(node[2*x+1], node[2*x+2]);
        }
    }

    T query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(b <= l || r <= a)    return def;
        if(a <= l && r <= b)    return node[k];
        T lx = query(a, b, 2*k+1, l, (l+r)/2);
        T rx = query(a, b, 2*k+2, (l+r)/2, r);
        return f(lx, rx);
    }
};

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i], v[i] -= k;
    for(int i = 1; i < n; i++)  v[i] += v[i-1];
    vector<ll> cp = v;
    cp.push_back(0);
    cp.push_back(-1ll<<60);
    cp.push_back(1ll<<60);
    sort(cp.begin(), cp.end());
    cp.erase(unique(cp.begin(),cp.end()),cp.end());
    auto f = [&](ll x)->int{
        return lower_bound(cp.begin(),cp.end(),x)-cp.begin();
    };
    int siz = cp.size();
    Seg<ll> seg(siz, 0, [](ll x, ll y){return x+y;});
    seg.update(f(0), 1);
    ll ret = 0;
    for(int i = 0; i < n; i++){
        ret += seg.query(0, f(v[i])+1);
        seg.update(f(v[i]), 1);
    }
    cout << ret << endl;
    return 0;
}
