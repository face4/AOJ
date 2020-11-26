#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll modpow(ll a, ll b, ll p = 10){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    n %= 10;
    ll tim = modpow(n%10, m);
    bool used[10] = {};
    vector<int> v;
    ll sum = 0;
    while(true){
        if(used[n]) break;
        v.push_back(n);
        sum += n;
        used[n] = true;
        n = n*tim%10;
    }
    int siz = v.size();
    ll ans = sum*(k/siz);
    k %= siz;
    for(int i = 0; i < k; i++)  ans += v[i];
    cout << ans << endl;
    return 0;
}