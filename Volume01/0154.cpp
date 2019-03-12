/*
// 枝狩り無し全探索だと流石にきついか？ -> 普通に0.43secで通った
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>> v;
int m, ans;

void dfs(int pos, int res){
    if(res == 0){
        ans++;
        return;
    }
    if(pos == m)    return;
    for(int j = min(v[pos].second, res/v[pos].first); j >= 0; j--){
        dfs(pos+1, res-j*v[pos].first);
    }
}

int main(){
    while(cin >> m, m){
        v.resize(m);
        for(int i = 0; i < m; i++)  cin >> v[i].first >> v[i].second;
        sort(v.rbegin(), v.rend());
        int g, n;
        cin >> g;
        while(g-- > 0){
            cin >> n;
            ans = 0;
            dfs(0, n);
            cout << ans << endl;
        }
    }
    return 0;
}
*/

// 恐らく想定解であるDP
#include<iostream>
using namespace std;

int main(){
    int m;
    while(cin >> m, m){
        int a, b, dp[1001] = {}, g, n;
        dp[0] = 1;
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            for(int j = 1000; j >= 0; j--){
                for(int k = 1; k <= b; k++){
                    if(j-a*k < 0)   break;
                    dp[j] += dp[j-a*k];
                }
            }
        }
        cin >> g;
        while(g-- > 0){
            cin >> n;
            cout << dp[n] << endl;
        }
    }
    return 0;
}