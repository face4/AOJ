#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// O(n*n + m*m*lim)
int main(){
    int lim, n, m, x;
    string s;
    while(cin >> lim >> n >> m >> x, lim){
        vector<int> v[11], dps(1001, 0);
        for(int i = 0; i < n; i++){
            int a, b;
            cin >> s >> a >> b;
            v[a].push_back(b);
        }
        for(int i = 1; i <= 10; i++)    sort(v[i].rbegin(), v[i].rend());
        for(int i = 1; i <= 10; i++){
            if(v[i].size() == 0)    continue;
            dps[i] = max(dps[i], v[i][0]);
            if(v[i].size() != 1)    dps[2*i] = max(dps[2*i], v[i][0]+v[i][1]);
            for(int j = 1; j <= 10; j++){
                if(i == j)  continue;
                if(v[j].size() == 0)    continue;
                dps[i+j] = max(dps[i+j], v[i][0]+v[j][0]);
            }
        }
        for(int i = 1; i <= lim; i++)   dps[i] = max(dps[i], dps[i-1]);

        for(int i = 1; i <= 10; i++)    v[i].clear();
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> s >> a >> b;
            v[a].push_back(b);
        }
        for(int i = 1; i <= 10; i++)    sort(v[i].rbegin(), v[i].rend());
        vector<vector<int>> dp(m+1, vector<int>(1001, -1));
        dp[0][0] = 0;
        for(int w = 1; w <= 10; w++){
            if(v[w].size() == 0)    continue;
            for(int i = m-1; i >= 0; i--){
                for(int j = lim; j >= 0; j--){
                    if(dp[i][j] == -1)  continue;
                    int val = 0;
                    for(int x = 0; i+x+1 <= m && j+(x+1)*w <= lim && x < v[w].size(); x++){
                        val += v[w][x];
                        dp[i+x+1][j+(x+1)*w] = max(dp[i+x+1][j+(x+1)*w], dp[i][j] + val);
                    }
                }
            }
        }
        vector<int> dpn(lim+1, 0);
        for(int i = x; i <= m; i++){
            for(int j = 0; j <= lim; j++){
                dpn[j] = max(dpn[j], dp[i][j]);
            }
        }
        
        for(int j = 1; j <= m; j++) dpn[j] = max(dpn[j], dpn[j-1]);

        int ans = 0;
        for(int i = 0; i <= lim; i++)   if(dps[i])  ans = max(ans, dps[i] + dpn[lim-i]);
        cout << ans << endl;
    }
    return 0;
}