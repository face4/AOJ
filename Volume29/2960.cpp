#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int p[4], t[4];
    for(int i = 0; i < 4; i++)  cin >> p[i];
    for(int i = 0; i < 4; i++)  cin >> t[i];

    vector<int> dp(300, 1<<29);
    dp[0] = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j+t[i] < 300; j++){
            dp[j+t[i]] = min(dp[j+t[i]], dp[j]+p[i]);
        }
    }

    int ans = 1<<29;
    for(int i = n; i <= 200; i++)   ans = min(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
