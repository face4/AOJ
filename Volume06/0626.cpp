#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    string s;
    cin >> n >> s;

    vector<ll> dp(2, 0), jdp(2, 0);
    jdp[0] = 1;
    ll origin = 0, jplus = 0, oplus = 0;
    ll icnt = count(s.begin(), s.end(), 'I');
    for(int i = 0; i < n; i++){
        oplus = max(oplus, dp[0]*icnt);
        if(s[i] == 'J') dp[0]++, jdp[0]++;
        if(s[i] == 'O') dp[1] += dp[0], jdp[1] += jdp[0];
        if(s[i] == 'I') origin += dp[1], jplus += jdp[1], icnt--;
    }
    ll iplus = dp[1]+origin;
    oplus += origin;
    cout << max({jplus, oplus, iplus}) << endl;
    return 0;
}