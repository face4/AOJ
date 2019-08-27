#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    vector<int> sum(n+1, 0);
    for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i-1];
    vector<int> lb;
    for(int i = 0; i+1 <= n; i++){
        for(int j = i+1; j <= n; j++){
            lb.push_back(sum[j]-sum[i]);
        }
    }
    sort(lb.begin(), lb.end());
    lb.erase(unique(lb.begin(),lb.end()), lb.end());
    int ans = 1<<30;
    for(int x : lb){
        vector<int> dp(n+1, 1<<30);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                if(i == n && j == 1)    continue;
                if(sum[i]-sum[j-1] < x)   continue;
                dp[i] = min(dp[i], max(dp[j-1], sum[i]-sum[j-1]));
            }
        }
        ans = min(ans, dp[n]-x);
    }
    cout << ans << endl;
    return 0;
}