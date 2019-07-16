#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

const ll INF = 1ll<<55;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        vector<vector<ll>> l(n, vector<ll>(n, INF)), s(n, vector<ll>(n, INF));
        for(int i = 0; i < n; i++)  l[i][i] = s[i][i] = 0;

        for(int i = 0; i < m; i++){
            ll x, y, t;
            string z;
            cin >> x >> y >> t >> z;
            x--, y--;
            if(z == "S"){
                ll to = min(s[x][y], t);
                s[x][y] = s[y][x] = to;
            }else{
                ll to = min(l[x][y], t);
                l[x][y] = l[y][x] = to;
            }
        }

        // 陸のみ,海のみを通ったときの全点対間最短距離
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    l[i][j] = min(l[i][j], l[i][k]+l[k][j]);
                    s[i][j] = min(s[i][j], s[i][k]+s[k][j]);
                }
            }
        }

        int r;
        cin >> r;
        vector<int> z(r);
        for(int i = 0; i < r; i++)  cin >> z[i], z[i]--;

        // dp[i][j] := 船をjに置いてz[i]まで到達した時のコスト
        vector<vector<ll>> dp(r, vector<ll>(n, INF));
        dp[0][z[0]] = 0;

        // 最初の町にいるときの船の位置を全て試す
        for(int i = 0; i < n; i++){
            if(s[z[0]][i] != INF && l[i][z[0]] != INF){
                dp[0][i] = min(dp[0][i], s[z[0]][i]+l[i][z[0]]);
            }
        }

        for(int i = 1; i < r; i++){
            // z[i-1] --(land)--> z[i]
            for(int j = 0; j < n; j++){
                dp[i][j] = min(dp[i][j], dp[i-1][j]+l[z[i-1]][z[i]]);
            }
            // z[i-1] --(land)-> j --(sea)-> k --(land)-> z[i]
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    dp[i][k] = min(dp[i][k], dp[i-1][j] + l[z[i-1]][j]+s[j][k]+l[k][z[i]]);
                }
            }
        }

        ll ans = INF;
        for(int i = 0; i < n; i++)  ans = min(ans, dp[r-1][i]);
        cout << ans << endl;
    }
    return 0;
}