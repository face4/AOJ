// 両側探索というアルゴリズムらしい(初めて知った)
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;

int dp[3628801][2] = {};
int fact[10];

int enc(string s){
    int cnt[10] = {};
    int ret = 0;
    for(int i = 0; i < s.length(); i++){
        int tmp = 0;
        for(int j = 0; j < s[i]-'0'; j++)   tmp += 1-cnt[j];
        ret += fact[s.length()-1-i]*tmp;
        cnt[s[i]-'0'] = 1;
    }
    return ret;
}

void f(int id, string ini, int n){
    dp[enc(ini)][id] = 0;
    queue<pair<string,int>> q;
    q.push({ini, enc(ini)});
    while(!q.empty()){
        pair<string,int> p = q.front();   q.pop();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                string cp = p.first;
                reverse(cp.begin()+i, cp.begin()+j+1);
                int ni = enc(cp);
                if(dp[ni][id] > dp[p.second][id]+1){
                    dp[ni][id] = dp[p.second][id]+1;
                    if(dp[ni][id] == 4) continue;
                    q.push({cp, ni});
                }
            }
        }
    }
}

int main(){
    fact[1] = 1;
    for(int i = 2; i < 10; i++) fact[i] = fact[i-1]*i;

    memset(dp, 0x3f, sizeof(dp));
    
    int n;
    cin >> n;
    
    string tmp = "", ideal = "";
    for(int i = 0; i < n; i++){
        int a;  cin >> a;
        tmp += ('0' + --a);
        ideal += ('0' + i);
    }
    
    f(0, tmp, n);
    f(1, ideal, n);
    
    int ans = n-1;
    for(int i = 0; i < 3628801; i++)    ans = min(ans, dp[i][0]+dp[i][1]);
    cout << ans << endl;
}

