#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i].first;
    for(int i = 0; i < n; i++)  cin >> v[i].second;
    int ans = 0;
    for(int i = 1; i < 1<<n; i++){
        vector<pair<int,int>> vp;
        for(int j = 0; j < n; j++){
            if((i>>j)&1)    vp.push_back(v[j]);
        }
        if(vp.size() > k)   continue;
        sort(vp.rbegin(), vp.rend());
        int tmp = 0, res = m;
        for(int i = 0; i < vp.size(); i++){
            int take = min(res, vp[i].second);
            tmp += take * vp[i].first;
            res -= take;
        }
        ans = max(ans, tmp+res);
    }
    cout << ans << endl;
    return 0;
}