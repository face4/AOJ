// 二進数を利用して品物の選択数を全列挙する
#include<iostream>
using namespace std;

int main(){
    int n, W;
    cin >> n >> W;
    int v[n], w[n], m[n];
    for(int i = 0; i < n; i++)  cin >> v[i] >> w[i] >> m[i];

    int dp[10001] = {};
    for(int i = 0; i < n; i++){
        for(int k = 0; m[i] > 0; k++){
            int partial = min(m[i], 1<<k);
            m[i] -= partial;
            for(int j = 10000-partial*w[i]; j >= 0; j--){
                dp[j+partial*w[i]] = max(dp[j+partial*w[i]], dp[j] + partial*v[i]);
            }
        }
    }

    int ans = 0;
    for(int i = W; i >= 0; i--) ans = max(ans, dp[i]);

    cout << ans << endl;

    return 0;
}