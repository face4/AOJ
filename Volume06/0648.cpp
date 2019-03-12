#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    vector<ll> sum(n+1);    sum[0] = 0;
    vector<pair<ll,ll>> vp;
    ll a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        vp.push_back({a,b});
    }
    sort(vp.begin(), vp.end());
    for(int i = 0; i < n; i++){
        sum[i+1] = sum[i] + vp[i].second;
    }

    ll ans = 0, tmpmin = 1ll<<60;
    for(int i = 1; i <= n; i++){
        tmpmin = min(tmpmin, sum[i-1]-vp[i-1].first);
        ans = max(ans, sum[i]-vp[i-1].first-tmpmin);
    }

    cout << ans << endl;

    return 0;
}