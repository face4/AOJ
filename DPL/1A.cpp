#include<iostream>
using namespace std;

const int INF = 1<<25;

int main(){
    int n, m;
    cin >> n >> m;

    int dp[n+1];
    dp[0] = 0;
    for(int i = 1; i < n+1; i++)    dp[i] = INF;

    int c;
    for(int i = 0; i < m; i++){
        cin >> c;

        for(int j = c; j < n+1; j++){
            dp[j] = min(dp[j], dp[j-c]+1);
        }
    }

    cout << dp[n] << endl;

    return 0;
}