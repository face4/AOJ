#include<iostream>
#include<vector>
using namespace std;

int main(){
    int c, n, m;
    cin >> c >> n >> m;
    vector<int> dp(c+1, 0);
    for(int i = 0; i < n; i++){
        int s, p;
        cin >> s >> p;
        for(int j = c; j-s >= 0; j--)   dp[j] = max(dp[j], dp[j-s]+p);
    }
    for(int i = 1; i <= m; i++){
        cout << dp[c/i]*i << endl;
    }
    return 0;
}