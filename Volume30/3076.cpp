#include<iostream>
using namespace std;
typedef long long ll;

const ll mod = 998244353;
ll modpow(ll a, ll b, ll p = mod){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

// 式を書いていたのにそれが二項係数であることに気付けなかった、反省
int main(){
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ll ans = 0, inv = modpow(2, mod-2);
    ll beki = modpow(2, n);
    for(int i = 0; i < n; i++){
        ll x;   cin >> x;
        beki *= inv;    beki %= mod;
        ans += beki * x % mod * modpow(x+1, i) % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
