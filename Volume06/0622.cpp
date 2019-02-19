#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n, q;
    ll t;
    cin >> n >> t >> q;

    ll d, a;
    vector<pair<ll,int>> x;
    vector<pair<ll,int>> v[2]; // 0-right, 1-left
    for(int i = 0; i < n; i++){
        cin >> d >> a;
        a--;
        v[a].push_back({d,i});
        x.push_back({d,a});
    }

    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());

    priority_queue<pair<ll,pii>, vector<pair<ll,pii>>, greater<pair<ll,pii>>> pq;
    for(pair<ll,int> p : v[0]){
        auto it = lower_bound(v[1].begin(), v[1].end(), p);
        if(it == v[1].end())    continue;
        pq.push({(*it).first-p.first, {p.second, (*it).second}});
    }

    set<ll> fixed;
    while(!pq.empty()){
        auto p = pq.top();  pq.pop();
        int l = p.second.first, r = p.second.second;
        ll dist = p.first;
        if(dist/2 > t)  break;
        auto itl = fixed.lower_bound(x[l].first), itr = fixed.lower_bound(x[r].first-dist/2);
        bool lb = itl == fixed.end() || *itl > x[l].first+dist/2;
        bool rb = itr == fixed.end() || *itr > x[r].first;
        if(lb && rb){
            fixed.insert(dist/2+x[l].first);
        }
    }

    int ask;
    for(int i = 0; i < q; i++){
        cin >> ask;
        ask--;
        if(x[ask].second == 0){
            auto it = fixed.lower_bound(x[ask].first);
            if(it == fixed.end() || *it > x[ask].first+t){
                cout << x[ask].first+t << endl;
            }else{
                cout << *it << endl;
            }
        }else{
            auto it = fixed.lower_bound(x[ask].first);
            if(it != fixed.begin()) it--;
            if(fixed.empty() || *it > x[ask].first || *it < x[ask].first-t){
                cout << x[ask].first-t << endl;
            }else{
                cout << *it << endl;
            }
        }
    }

    return 0;
}