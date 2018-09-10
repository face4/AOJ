// 半分全列挙
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

int n;
ll W, v, w;

struct data{
    ll first, second;
    data(ll _v, ll _w) : first(_v), second(_w) {}
    bool operator<(const data other) const{
        return second < other.second;
    }
};

vector<data> countup(int x){
    map<ll, ll> half;
    for(int i = 0; i < x; i++){
        cin >> v >> w;
        if(w > W)   continue;
        map<ll, ll> tmp;
        tmp[w] = v;
        for(pair<ll, ll> p : half){
            // do not bring it
            if(tmp.count(p.first))  tmp[p.first] = max(tmp[p.first], half[p.first]);
            else                    tmp[p.first] = half[p.first];
            
            // bring it
            ll sum = p.first + w;
            if(sum > W) continue;
            if(tmp.count(sum))  tmp[sum] = max(tmp[sum], half[p.first] + v);
            else                tmp[sum] = half[p.first] + v;
        }
        half = tmp;
    }

    vector<data> zrk;
    for(pair<ll,ll> p : half)   zrk.push_back(data(p.second, p.first));
    sort(zrk.begin(), zrk.end());
    return zrk;
}

int main(){
    cin >> n >> W;

    int a = (n+1)/2;
    int b = n-a;

    vector<data> one = countup(a);
    vector<data> two = countup(b);
    
    static ll accumone[1<<21] = {}, accumtwo[1<<21] = {};
    
    if(one.size()){
        accumone[0] = one[0].first;
        for(int i = 1; i < one.size(); i++){
            accumone[i] = max(accumone[i-1], one[i].first);
        }
    }

    if(two.size()){
        accumtwo[0] = two[0].first;
        for(int i = 1; i < two.size(); i++){
            accumtwo[i] = max(accumtwo[i-1], two[i].first);
        }
    }

    ll ans = 0;
    for(data d : one){
        ans = max(ans, d.first);
        ll rest = W - d.second;
        int pos = (upper_bound(two.begin(), two.end(), data(0,rest)) - two.begin());
        if(pos == 0)    continue;
        pos--;
        ans = max(ans, d.first + accumtwo[pos]);
    }

    for(data d : two){
        ans = max(ans, d.first);
        ll rest = W - d.second;
        int pos = (upper_bound(one.begin(), one.end(), data(0,rest)) - one.begin());
        if(pos == 0)    continue;
        pos--;
        ans = max(ans, d.first + accumone[pos]);
    }

    cout << ans << endl;

    return 0;
}