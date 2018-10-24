#include<iostream>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

int main(){
    int n;
    string s, t;
    
    cin >> n >> s >> t;

    ll cnt[26] = {};

    cnt[s[0]-'a'] = 1;

    for(int i = 1; i < n-1; i++){
        cnt[s[i]-'a'] += cnt[t[i]-'a'];
        cnt[s[i]-'a'] %= mod;
    }

    cout << cnt[t[n-1]-'a']%mod << endl;

    return 0;
}