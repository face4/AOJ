#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n;
    cin >> n;
    vector<pii> va, vb;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        va.push_back({x, i});
    }
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        vb.push_back({x, i});
    }
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    vector<pii> v[n];
    for(int i = 0; i < n; i++){
        int aind = va[i].second, bind = vb[i].second;
        if(i > 0){
            v[aind].push_back({va[i-1].second, va[i].first-va[i-1].first});
            v[bind].push_back({vb[i-1].second, vb[i].first-vb[i-1].first});
        }
        if(i+1 < n){
            v[aind].push_back({va[i+1].second, va[i+1].first-va[i].first});
            v[bind].push_back({vb[i+1].second, vb[i+1].first-vb[i].first});
        }
    }
    vector<ll> dp(n, 1ll<<60);
    priority_queue<pair<ll,int>> pq;
    pq.push({-0, 0});
    dp[0] = 0;
    while(!pq.empty()){
        auto p = pq.top();  pq.pop();
        ll cost = -p.first;
        int ind = p.second;
        if(dp[ind] != cost) continue;
        for(pii P : v[ind]){
            if(dp[P.first] > dp[ind] + P.second){
                dp[P.first] = dp[ind] + P.second;
                pq.push({-dp[P.first], P.first});
            }
        } 
    }
    for(int i = 0; i < n; i++)  cout << dp[i] << endl;
    return 0;
}