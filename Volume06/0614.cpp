#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

struct STlazy{
private:
    vector<ll> node, lazy;
    int n;
public:
    STlazy(int siz){
        n = 1;
        while(n < siz)  n *= 2;
        node.resize(2*n-1, 0);
        lazy.resize(2*n-1, 0);
    }

    void eval(int k, int l, int r){
        if(lazy[k] == 0)    return;
        node[k] += lazy[k];
        if(r-l > 1){
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
            lazy[k] += (r-l)*x;
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
        return lx+rx;
    }
};

// これでも一応AC
int seg_main(){
    int n, m;
    cin >> n >> m;
    STlazy st(n);
    int bef, aft;
    cin >> bef; bef--;
    for(int i = 1; i < m; i++){
        cin >> aft; aft--;
        st.add(min(bef, aft), max(bef, aft), 1);
        bef = aft;
    }
    ll a, b, c, ans = 0;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b >> c;
        ll tmp = (ll)(st.query(i, i+1));
        ans += min(tmp*a, tmp*b+c);
    }
    cout << ans << endl;
    return 0;
}

int main(){
    int n, m;
    cin >> n >> m;

    int cnt[100002] = {};
    int bef, aft;
    cin >> bef;
    for(int i = 1; i < m; i++){
        cin >> aft;
        cnt[min(bef,aft)]++, cnt[max(bef,aft)]--;
        bef = aft;
    }
    for(int i = 1; i < n+1; i++)    cnt[i] += cnt[i-1];

    ll ans = 0, a, b, c;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b >> c;
        ans += min(a*cnt[i+1], b*cnt[i+1]+c);
    }

    cout << ans << endl;
    
    return 0;
}