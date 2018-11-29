#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        ll k[n];
        for(int i = 0; i < n; i++)  cin >> k[i], k[i] %= m;
        for(int i = 1; i < n; i++)  k[i] = (k[i]+k[i-1])%m;
        set<ll> s;
        s.insert(0);
        ll ans = 0;
        for(int i = 0; i < n; i++){
            auto r = s.upper_bound(k[i]);
            if(r == s.end())    r = s.begin();
            ans = max(ans, (k[i]-(*r)+m)%m);
            s.insert(k[i]);
        }
        cout << ans << endl;
    }
    return 0;
}