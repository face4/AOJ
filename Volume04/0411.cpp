#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n, l;
    cin >> n >> l;
    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
        int p, d;
        cin >> p >> d;
        vp.push_back({p, d});
    }
    sort(vp.begin(), vp.end());
    vector<ll> dpl(n), dpr(n);
    for(int i = 0; i < n; i++){
        dpl[i] = (i==0 ? 0 : dpl[i-1]) + (vp[i].second==0 ? 1 : -1)*(vp[i].first-i-1);
    }
    for(int i = n-1; i >= 0; i--){
        dpr[i] = (i==n-1 ? 0 : dpr[i+1]) + (vp[i].second==1 ? 1 : -1)*(l-(n-1-i)-vp[i].first);
    }
    ll ans = max(dpl.back(), dpr[0]);
    for(int i = 0; i+1 < n; i++){
        ans = max(ans, dpl[i]+dpr[i+1]);
    }
    cout << ans << endl;
    return 0;
}