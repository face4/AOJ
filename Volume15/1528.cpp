#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct data{
    int p, d, t;
};

int main(){
    int l, n;
    cin >> l >> n;
    
    vector<int> comp;
    comp.push_back(0);
    comp.push_back(l);
    int p, d, t;
    vector<data> vd;
    for(int i = 0; i < n; i++){
        cin >> p >> d >> t;
        vd.push_back(data({p,d,t}));
        comp.push_back(p);
        comp.push_back(p+d);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    auto pos = [&](int val)->int{
        return lower_bound(comp.begin(), comp.end(), val)-comp.begin();
    };
    
    int axis = comp.size();
    vector<pair<int,int>> warp[axis];
    for(int i = 0; i < n; i++){
        warp[pos(vd[i].p)].push_back({vd[i].d, vd[i].t});
    }

    vector<int> dp(axis, 1<<30);
    dp[0] = 0;
    for(int i = 0; i < axis; i++){
        for(int j = i+1; j < axis; j++){
            dp[j] = min(dp[j], dp[i] + (comp[j]-comp[i]));
        }
        for(pair<int,int> w : warp[i]){
            int next = pos(comp[i]+w.first);
            dp[next] = min(dp[next], dp[i]+w.second);
        }
    }

    cout << dp[axis-1] << endl;
    
    return 0;
}