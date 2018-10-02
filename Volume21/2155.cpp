#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        vector<pair<int, pair<int,int>>> v;
        int t, s, d;
        for(int i = 0; i < m; i++){
            cin >> t >> s >> d;
            v.push_back({t,{s,d}});
        }
        sort(v.begin(), v.end());

        bool infected[20001] = {};
        infected[1] = true;

        for(auto p : v){
            if(infected[p.second.first]){
                infected[p.second.second] = true;
            }
        }

        int cnt = 0;
        for(int i = 1; i <= n; i++) if(infected[i]) cnt++;

        cout << cnt << endl;
    }
    return 0;
}