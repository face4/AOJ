#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int m, n, k;
    cin >> m >> n >> k;
    set<pii> sw;
    set<int> yoko[n+1], tate[m+1];
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        sw.insert({x, y});
    }
    set<pii> s = sw;
    s.insert({1, 1});
    s.insert({m, n});
    map<pii,int> id;
    vector<pii> v;
    int siz = 0;
    for(pii p : s){
        id[p] = siz++;
        v.push_back(p);
        int x = p.first, y = p.second;
        yoko[y].insert(x);
        tate[x].insert(y);
    }
    vector<vector<ll>> dp(2, vector<ll>(siz, 1ll<<60));
    dp[0][0] = 0;
    priority_queue<pair<ll,pii>> pq;
    pq.push({-0, {0, 0}});
    while(!pq.empty()){
        auto p = pq.top();  pq.pop();
        ll cost = -p.first;
        int pos = p.second.first, stat = p.second.second;
        int x = v[pos].first, y = v[pos].second;
        if(sw.count({x,y})>0 && dp[1-stat][pos] > dp[stat][pos]+1){
            dp[1-stat][pos] = dp[stat][pos]+1;
            pq.push({-dp[1-stat][pos], {pos, 1-stat}});
        }
        if(stat == 1){
            auto it = yoko[y].lower_bound(x);
            if(it != yoko[y].begin()){
                it--;
                ll nc = x-(*it);
                int npos = id[{*it,y}];
                if(dp[stat][npos] > dp[stat][pos]+nc){
                   dp[stat][npos] = dp[stat][pos]+nc;
                   pq.push({-dp[stat][npos], {npos, stat}});
                }
                it++;
            }
            it++;
            if(it != yoko[y].end()){
                ll nc = (*it)-x;
                int npos = id[{*it,y}];
                if(dp[stat][npos] > dp[stat][pos]+nc){
                   dp[stat][npos] = dp[stat][pos]+nc;
                   pq.push({-dp[stat][npos], {npos, stat}});
                }
            }
        }else if(stat == 0){
            auto it = tate[x].lower_bound(y);
            if(it != tate[x].begin()){
                it--;
                ll nc = y-(*it);
                int npos = id[{x, *it}];
                if(dp[stat][npos] > dp[stat][pos]+nc){
                   dp[stat][npos] = dp[stat][pos]+nc;
                   pq.push({-dp[stat][npos], {npos, stat}});
                }
                it++;
            }
            it++;
            if(it != tate[x].end()){
                ll nc = (*it)-y;
                int npos = id[{x, *it}];
                if(dp[stat][npos] > dp[stat][pos]+nc){
                   dp[stat][npos] = dp[stat][pos]+nc;
                   pq.push({-dp[stat][npos], {npos, stat}});
                }
            }
        }
    }
    ll ret = min(dp[0][siz-1], dp[1][siz-1]);
    if(ret == 1ll<<60)  ret = -1;
    cout << ret << endl;
    return 0;
}