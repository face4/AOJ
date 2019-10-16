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

int main(){
    ll m, n, k;
    cin >> m >> n >> k;
    ll ans = modpow(m, n);
    ll sub = 0, mcomb = 1;
    for(int i = 1; i < min(k, m+1); i++){
        ll tmp = 0, comb = 1;
        for(int j = 1; j <= i; j++){
            ll x = (i-j)%2 == 0 ? 1 : -1;
            comb = comb*modpow(j,mod-2)%mod*(i-j+1)%mod;
            tmp += x*(comb*modpow(j,n)%mod);
            tmp = (tmp + mod)%mod;
        }
        mcomb = mcomb*modpow(i,mod-2)%mod*((m-i+1)%mod)%mod;
        tmp = tmp*mcomb%mod;
        sub += tmp;
        sub %= mod;
    }
    cout << (ans-sub+mod)%mod << endl;
    return 0;
}
