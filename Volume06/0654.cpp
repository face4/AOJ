#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    vector<int> dp(n, 0);
    dp[1] = (s[0] != s[1]);
    for(int i = 2; i < n; i++)  dp[i] = max(dp[i-1], (s[i]!=s[i-1])*(dp[i-2]+1));
    cout << dp[n-1] << endl;
    return 0;
}