#include<iostream>
#include<vector>
using namespace std;

typedef unsigned long long ull;
const ull x = 1000000007;

bool contains(string str, string pre){
    int slen = str.length(), plen = pre.length();
    if(slen < plen) return false;
    ull target = 0;
    for(int i = 0; i < plen; i++){
        target = target * x + pre[i];
    }
    ull tmp = 1;
    for(int i = 0; i < plen; i++)   tmp *= x;
    ull val = 0;
    for(int i = 0; i < plen; i++)   val = val*x + str[i];
    for(int i = plen; i <= slen; i++){
        if(val == target)   return true;
        if(i < slen)    val = val * x - str[i-plen]*tmp + str[i];
    }
    return false;
}

int f(string s, string t){
    int k = min(s.length(), t.length()), slen = s.length();
    int ret = 0;
    ull a = 0, b = 0, tmp = 1;
    for(int i = 1; i <= k; i++){
        a = a + s[slen-i]*tmp;
        b = b*x + t[i-1];
        if(a == b)  ret = i;
        tmp *= x;
    }
    return t.length()-ret;
}

int main(){
    int n;
    while(cin >> n, n){
        vector<string> v(n);
        for(int i = 0; i < n; i++)  cin >> v[i];
        vector<string> s;
        for(int i = 0; i < n; i++){
            bool tmp = false;
            for(int j = 0; j < n; j++){
                if(i == j)    continue;
                tmp |= contains(v[j], v[i]);
            }
            if(!tmp)    s.push_back(v[i]);
        }
        n = s.size();
        vector<vector<int>> dp(n, vector<int>(1<<n, 1<<30));
        for(int i = 0; i < n; i++)  dp[i][1<<i] = s[i].length();
        for(int b = 0; b < 1<<n; b++){
            for(int i = 0; i < n; i++){
                if(dp[i][b] == 1<<30)   continue;
                for(int j = 0; j < n; j++){
                    if((b>>j)&1)    continue;
                    dp[j][b|(1<<j)] = min(dp[j][b|(1<<j)], dp[i][b] + f(s[i], s[j]));
                }
            }
        }
        int ans = 1<<30;
        for(int i = 0; i < n; i++){
            ans = min(ans, dp[i][(1<<n)-1]);
        }
        cout << ans << endl;
    }
    return 0;
}