#include<iostream>
#include<vector>
#include<functional>
#include<climits>
#include<algorithm>
#include<iomanip>
using namespace std;

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
        node[x] = val; /* ! */
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
    int n;
    cin >> n;
    vector<int> xs, t(n), a(n);
    for(int i = 0; i < n; i++){
        cin >> t[i] >> a[i];
        xs.push_back(t[i]);
    }
    int q;
    cin >> q;
    vector<int> l(q), r(q);
    for(int i = 0; i < q; i++){
        cin >> l[i] >> r[i];
        xs.push_back(l[i]);
        xs.push_back(r[i]);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    int siz = xs.size();
    auto f = [&](int x)->int{
        return lower_bound(xs.begin(),xs.end(),x)-xs.begin();
    };
    Seg<double> seg(siz, 1.0, [](double x, double y){return x*y;});
    for(int i = 0; i < n; i++){
        seg.update(f(t[i]), (100-10*a[i])/100.0);
    }
    for(int i = 0; i < q; i++){
        cout << fixed << setprecision(12) << 1000000000*seg.query(f(l[i]), f(r[i])) << endl;
    }
    return 0;
}
