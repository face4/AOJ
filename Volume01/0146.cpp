#include<iostream>
#include<vector>
#include<cfloat>
#include<algorithm>
using namespace std;

const double INF = DBL_MAX;

int main(){
    int n;
    cin >> n;
    vector<int> s(n), d(n), v(n);
    for(int i = 0; i < n; i++)  cin >> s[i] >> d[i] >> v[i];
    vector<vector<double>> dp(n, vector<double>(1<<n, INF));
    vector<vector<int>> back(n, vector<int>(1<<n, -1));
    for(int i = 0; i < n; i++){
        dp[i][1<<i] = 0;
    }
    for(int s = 0; s < 1<<n; s++){
        for(int i = 0; i < n; i++){
            if(((s>>i)&1) == 0) continue;
            double w = 0;
            for(int k = 0; k < n; k++)  if((s>>k)&1)    w += v[k];
            w *= 20;
            for(int j = 0; j < n; j++){
                if((s>>j)&1)    continue;
                if(dp[j][s|(1<<j)] > dp[i][s] + abs(d[i]-d[j])/2000.0*(70+w)){
                    dp[j][s|(1<<j)] = dp[i][s] + abs(d[i]-d[j])/2000.0*(70+w);
                    back[j][s|(1<<j)] = i;
                }
            }
        }
    }
    vector<int> ans;
    int pos = -1, bit = (1<<n)-1;
    double tim = INF;
    for(int j = 0; j < n; j++){
        if(dp[j][(1<<n)-1] < tim){
            tim = dp[j][bit];
            pos = j;
        }
    }
    while(pos != -1){
        ans.push_back(s[pos]);
        int nbit = bit^(1<<pos);
        pos = back[pos][bit];
        bit = nbit;
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < n; i++){
        cout << ans[i] << " \n"[i==n-1];
    }
    return 0;
}