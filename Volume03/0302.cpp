#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> P;
typedef long long ll;

int main(){
    int n, D;
    cin >> n >> D;
    vector<pii> v;
    vector<int> x(n), y(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> b[i];
        v.push_back({b[i],i});
    }
    sort(v.begin(), v.end());
    vector<bool> ng(n, 0);
    priority_queue<pii> l, r, u, d;
    ll ans = 0;
    for(int j = 0; j < n; j++){
        int i = v[j].second;
        int to = v[j].first;
        l.push({-x[i], i}); d.push({-y[i], i});
        r.push({x[i], i});  u.push({y[i], i});
        bool update = true;
        while(update){
            update = false;
            while(!l.empty()&&(ng[l.top().second]||abs(b[l.top().second]-to)>D)){
                ng[l.top().second] = true;  l.pop();    update = true;
            }
            while(!d.empty()&&(ng[d.top().second]||abs(b[d.top().second]-to)>D)){
                ng[d.top().second] = true;  d.pop();    update = true;
            }
            while(!r.empty()&&(ng[r.top().second]||abs(b[r.top().second]-to)>D)){
                ng[r.top().second] = true;  r.pop();    update = true;
            }
            while(!u.empty()&&(ng[u.top().second]||abs(b[u.top().second]-to)>D)){
                ng[u.top().second] = true;  u.pop();    update = true;
            }
        }
        // printf("%d %d %d %d\n", r.top().first, l.top().first, u.top().first, d.top().first);
        ans = max(ans, (ll)(r.top().first+l.top().first)*(u.top().first+d.top().first));
    }
    cout << ans << endl;
    return 0;
}