#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[300][300];
string ans;

int getLCSlen(string a, string b){
    memset(dp, 0, sizeof(dp));
    int ret = 0;

    for(int j = 0; j < b.length(); j++) if(a[0] == b[j])    dp[0][j] = 1, ret = 1;
    for(int i = 0; i < a.length(); i++) if(a[i] == b[0])    dp[i][0] = 1, ret = 1;
    
    // add these if you want to get longest common subsequence
    for(int i = 1; i < a.length(); i++) dp[i][0] = max(dp[i][0], dp[i-1][0]);
    for(int j = 1; j < b.length(); j++) dp[0][j] = max(dp[0][j], dp[0][j-1]);

    for(int i = 1; i < a.length(); i++){
        for(int j = 1; j < b.length(); j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1]+1;
                ret = max(ret, dp[i][j]);
            }
            // add these if you want to get longest common subsequence
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
            ret = max(ret, dp[i][j]);
        }
    }
    return ret;
}

void solve(string s){
    ans = "";
    for(int x = 1; x < s.length(); x++){
        int len = getLCSlen(s.substr(0,x), s.substr(x));
        if(len > ans.length()){
            string tmp = "";
            int i = x-1, j = s.length()-x-1;
            while(i >= 0 && j >= 0 && dp[i][j]>0){
                while(i > 0 && dp[i-1][j]==dp[i][j])    i--;
                while(j > 0 && dp[i][j-1]==dp[i][j])    j--;
                tmp += s[i];
                i--, j--;
            }
            ans = tmp;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main(){
    string s;
    while(cin >> s, s != "#END"){
        solve(s);
    }
    return 0;
}