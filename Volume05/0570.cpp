#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

// less - decsend - pos - residual - val
int dp[2][2][501][500][10];
const int mod = 10000;

int calc(string s, int m){
    if(s == "0")    return 0;
    memset(dp, 0, sizeof(dp));
    int n = s.length();
    for(int i = 0; i < n; i++){
        for(int less = 0; less < 2; less++){
            for(int dec = 0; dec < 2; dec++){
                for(int res = 0; res < m; res++){
                    for(int val = 0; val < 10; val++){
                        if(dp[less][dec][i][res][val] == 0) continue;
                        for(int nval = 0; nval < 10; nval++){
                            if(less == 0 && nval > s[i]-'0')    break;
                            if(val == nval || dec == (val > nval)) continue;
                            int nless = less || (s[i]-'0' > nval);
                            int ndec = 1-dec;
                            int nres = (res*10+nval)%m;
                            (dp[nless][ndec][i+1][nres][nval] += dp[less][dec][i][res][val]) %= mod;
                        }
                    }
                }
            }
        }
        // begin number here
        for(int nval = 1; nval <= 9; nval++){
            if(i == 0 && nval > s[i]-'0')   break;
            int less = (i==0&&nval==s[i]-'0' ? 0 : 1);
            for(int dec = 0; dec < 2; dec++){
                dp[less][dec][i+1][nval%m][nval]++;
            }
        }
    }
    int ret = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 10; k++){
                (ret += dp[i][j][n][0][k]) %= mod;
            }
        }
    }
    int ma = 9;
    if(s.length() == 1) ma = stoi(s);
    for(int i = 1; i <= ma; i++){
        if(i%m == 0)    ret--;
    }
    ret = (ret + mod) % mod;
    return ret;
}

int main(){
    string a, b;
    cin >> a >> b;
    int m;
    cin >> m;
    for(int i = a.length()-1; i >= 0; i--){
        if(a[i] != '0'){
            a[i]--;
            break;
        }else{
            a[i] = '9';
        }
    }
    reverse(a.begin(), a.end());
    while(a.size() > 1 && a.back() == '0')  a.pop_back();
    reverse(a.begin(), a.end());
    cout << (calc(b,m)-calc(a,m)+mod)%mod << endl;
    return 0;
}