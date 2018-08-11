#include<iostream>
using namespace std;

int dp[101][10001] = {};
int val[101], wei[101];

int main(){
    int n, w;
    cin >> n >> w;

    for(int i = 1; i <= n; i++)  cin >> val[i] >> wei[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            if(wei[i] > j)
                dp[i][j] = dp[i-1][j];
            else if(wei[i] <= j)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-wei[i]] + val[i]);
        }
    }

    cout << dp[n][w] << endl;

    return 0;
}