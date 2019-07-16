#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int n, q, s, t;

inline ll foehn(ll a){
    return a > 0 ? -s*a : t*(-a);
}

int main(){
    scanf("%d %d %d %d", &n, &q, &s, &t);
    vector<ll> a(n+1, 0), d(n+1, 0);
    ll ans = 0;
    scanf("%lld", a.begin());
    for(int i = 1; i <= n; i++){
        scanf("%lld", a.begin()+i);
        d[i] = a[i] - a[i-1];
        ans += foehn(d[i]);
    }
    int l, r, x;
    while(q-- > 0){
        scanf("%d %d %d", &l, &r, &x);
        ll bef = foehn(d[l]);
        d[l] += x;
        ll aft = foehn(d[l]);
        ans += aft-bef;
        if(r < n){
            bef = foehn(d[r+1]);
            d[r+1] -= x;
            aft = foehn(d[r+1]);
            ans += aft-bef;
        }
        cout << ans << endl;
    }
    return 0;
}