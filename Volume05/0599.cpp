#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    vector<int> p(m);
    for(int i = 0; i < m; i++)  cin >> p[i];
    sort(p.rbegin(), p.rend());
    for(int i = 1; i < m; i++)  p[i] += p[i-1];
    vector<int> c(n), e(n);
    for(int i = 0; i < n; i++)  cin >> c[i] >> e[i];
    vector<int> dp(20002, 1<<30);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 20000-c[i]; j >= 0; j--){
            dp[j+c[i]] = min(dp[j+c[i]], dp[j]+e[i]);
        }
    }
    for(int i = 20000; i >= 0; i--) dp[i] = min(dp[i], dp[i+1]);
    int ans = 0;
    for(int i = m; i > 0; i--){
        ans = max(ans, p[i-1]-dp[i]);
    }
    cout << ans << endl;
    return 0;
}