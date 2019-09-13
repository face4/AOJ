#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int INF = 1<<28;
const int START = 108;
const int GOAL = 109;

int enc(string s){
    if(s == "H")        return START;
    else if(s == "D")   return GOAL;
    char c = s[0];
    int x = stoi(s.substr(1));
    return (c == 'C' ? 0 : 6) + x-1;
}

int main(){
    int m, n, k, d;
    while(cin >> m >> n >> k >> d, m+n+k+d){
        vector<pair<int,int>> vp[110];
        vector<int> cake(m);
        for(int i = 0; i < m; i++)  cin >> cake[i];
        while(d-- > 0){
            string a, b;
            int c;
            cin >> a >> b >> c;
            int from = enc(a), to = enc(b);
            c *= k;
            vp[from].push_back({to, c});
            vp[to].push_back({from, c});
        }
        vector<vector<int>> dp(110, vector<int>(1<<m, INF));
        dp[START][0] = 0;

        for(int loop = 0; loop < 110*64; loop++){
            bool update = false;
            for(int pos = 0; pos < 110; pos++){
                for(pair<int,int> p : vp[pos]){
                    for(int bit = 0; bit < 1<<m; bit++){
                        if(dp[pos][bit] == INF) continue;
                        int next = p.first, ncost = dp[pos][bit]+p.second;
                        if(next < m){
                            if((bit>>next&1)==0 && ncost-cake[next] < dp[next][bit^(1<<next)]){
                                dp[next][bit^(1<<next)] = ncost-cake[next];
                                update = true;
                            }
                            continue;
                        }
                        if(ncost < dp[next][bit]){
                            dp[next][bit] = ncost;
                            update = true;
                        }
                    }
                }
            }
            if(!update) break;
        }

        int ans = 1<<30;
        for(int i = 0; i < 1<<m; i++){
            ans = min(ans, dp[GOAL][i]);
        }
        cout << ans << endl;
    }
    return 0;
}
