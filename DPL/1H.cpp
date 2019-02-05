// 半分全列挙
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
const ll INF = 1ll<<60;

int n;
ll W;
vector<ll> v, w;

ll half(){
    int n1 = n/2;
    vector<pair<ll,ll>> vp;
    for(int i = 0; i < 1<<n1; i++){
        ll tmpw = 0, tmpv = 0;
        for(int j = 0; j < n1; j++){
            if((i>>j)&1)    tmpw += w[j], tmpv += v[j];
        }
        vp.push_back({tmpw, tmpv});
    }
    sort(vp.begin(), vp.end());
    int cur = 1;
    for(int i = 1; i < vp.size(); i++){
        if(vp[i].second > vp[cur-1].second){
            vp[cur++] = vp[i];
        }
    }
    ll ret = 0;
    for(int i = 0; i < 1<<(n-n1); i++){
        ll tmpw = 0, tmpv = 0;
        for(int j = 0; j < (n-n1); j++){
            if((i>>j)&1)    tmpw += w[n1+j], tmpv += v[n1+j];
        }
        if(tmpw > W)    continue;
        pair<ll,ll> tmp = make_pair(W-tmpw, INF);
        auto it = upper_bound(vp.begin(), vp.begin()+cur, tmp);
        it--;
        if(tmpw + (*it).first <= W)   ret = max(ret, (*it).second + tmpv);
    }
    return ret;
}

int main(){
    cin >> n >> W;
    v.resize(n), w.resize(n);
    for(int i = 0; i < n; i++)  cin >> v[i] >> w[i];
    cout << half() << endl;
    return 0;
}