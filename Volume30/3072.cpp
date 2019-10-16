#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll modpow(ll a, ll b, ll p = 998244353){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

const int mod = 998244353;

int main(){
    int n, k, a;
    cin >> n >> k >> a;
    vector<int> v(k-1+n+1, 0), acc(k-1+n+1, 0);
    a = (ll)a * modpow(100, mod-2, mod) % mod;
    int invn = modpow(n, mod-2, mod);
    for(int i = 1; i <= n; i++) v[i] = invn;
    acc[1] = v[1];
    for(int i = 2; i <= k-1+n; i++){ 
        int bef = acc[min(i-1, k-1)] - acc[max(0, i-1-n)];
        if(bef < 0) bef += mod;
        bef = (int)((ll)bef * a % mod * invn % mod);
        v[i] = (v[i] + bef)%mod;
        acc[i] = (acc[i-1]+v[i])%mod;
    }
    int ans = 0;
    for(int i = k; i <= k-1+n; i++) ans = (ans + v[i])%mod;
    cout << ans << endl;
    return 0;
}
