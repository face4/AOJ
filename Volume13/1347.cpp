#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    // editorial解
    // 重なる区間を1発で済ませてしまえば良いことが自明なので
    // いもしてホイ
    int n, m;
    cin >> n >> m; 
    int imos[1005] = {};
    for(int i = 0; i < m; i++){
        int c, d;
        cin >> c >> d;
        imos[c]++, imos[d]--;
    }
    int ans = n+1;
    for(int i = 1; i <= n; i++){
        imos[i] += imos[i-1];
        if(imos[i]) ans += 2;
    }
    cout << ans << endl;
    return 0;


    // 自分の回答(AC)
    // int n, m;
    // cin >> n >> m;
    // if(m == 0){
    //     cout << n+1 << endl;
    //     return 0;
    // }
    // vector<int> dp(m, 1<<30);
    // vector<pair<int,int>> vp;
    // for(int i = 0; i < m; i++){
    //     int c, d;
    //     cin >> c >> d;
    //     vp.push_back({d, c});
    // }
    // sort(vp.begin(), vp.end());
    // for(int i = 0; i < m; i++){
    //     int to = vp[i].first, from = vp[i].second;
    //     for(int j = i; j >= 0; j--){
    //         from = min(from, vp[j].second);
    //         dp[i] = min(dp[i], (j==0 ? 0 : dp[j-1])+(to-from)*2);
    //     }
    // }
    // cout << dp[m-1]+n+1 << endl;
    // return 0;
}