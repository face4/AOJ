#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

struct STlazy{
private:
    int n;
    vector<ll> node, lazy;

public:
    STlazy(){
        n = (1<<17)-1;
        node.resize(2*n-1, 0);
        lazy.resize(2*n-1, 0);
    }

    void eval(int k, int l, int r){
        if(lazy[k] == 0)    return;
        node[k] += lazy[k];
        if(r - l > 1){
            lazy[2*k+1] += lazy[k]/2;
            lazy[2*k+2] += lazy[k]/2;
        }
        lazy[k] = 0;
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        eval(k, l, r);
        if(r <= a || b <= l)    return;
        if(a <= l && r <= b){
            lazy[k] += (r-l) * x;
            eval(k, l, r);
            return;
        }
        add(a, b, x, 2*k+1, l, (l+r)/2);
        add(a, b, x, 2*k+2, (l+r)/2, r);
        node[k] = node[2*k+1] + node[2*k+2];
    }

    ll query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        eval(k, l, r);
        if(a <= l && r <= b)    return node[k];
        ll lx = query(a, b, 2*k+1, l, (l+r)/2);
        ll rx = query(a, b, 2*k+2, (l+r)/2, r);
        return lx + rx;
    }
};

int main(){
    int n, q;
    cin >> n >> q;

    STlazy st;
    int a, b, c, d;
    while(q-- > 0){
        cin >> a >> b >> c;
        if(a == 0){
            cin >> d;
            st.add(b, c+1, d);
        }else{
            cout << st.query(b, c+1) << endl;
        }
    }

    return 0;
}