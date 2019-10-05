#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool contains(string str, string pre){
    int s = str.length(), p = pre.length();
    if(s < p)   return false;

    for(int i = 0; i <= s - p; i++){
        int j;
        for(j = 0; j < p; j++){ 
            if(str[i+j] != pre[j])  break;
        }
        if(j == p)  return true;
    }

    return false;
}

typedef unsigned long long ull;
ull x = 1000000007;

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
    return ret;
}

int main(){
    int n;
    while(cin >> n, n){
        vector<string> v;
        for(int i = 0; i < n; i++){
            string s;   cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        n = v.size();
        vector<string> x;
        for(int i = 0; i < n; i++){
            bool valid = true;
            for(int j = 0; j < n; j++){
                if(i == j)  continue;
                if(contains(v[j], v[i]))    valid = false;
            }
            if(valid)   x.push_back(v[i]);
        }
        int n = x.size();
        vector<vector<string>> dp(n, vector<string>(1<<n, ""));
        for(int i = 0; i < n; i++)  dp[i][1<<i] = x[i];
        for(int s = 1; s < 1<<n; s++){
            for(int i = 0; i < n; i++){
                if(((s>>i)&1) == 0)    continue;
                for(int j = 0; j < n; j++){
                    if((s>>j)&1)    continue;
                    string tmp = dp[i][s];
                    tmp += x[j].substr(f(dp[i][s], x[j]));
                    int nbit = s + (1<<j);
                    if(dp[j][nbit] == "" || tmp.length() < dp[j][nbit].length() || (tmp.length()==dp[j][nbit].length() && tmp < dp[j][nbit])){
                        dp[j][nbit] = tmp;
                    }
                }
            }
        }
        string ans = dp[0].back();
        for(int i = 1; i < n; i++){
            if(ans.length() > dp[i].back().length() || (ans.length()==dp[i].back().length() && ans > dp[i].back())){
                ans = dp[i].back();
            }
        }
        cout << ans << endl;
    }
    return 0;
}
