#include<iostream>
#include<climits>
using namespace std;

const int INF = INT_MAX;

int main(){
    int n, m;
    cin >> n >> m;

    int d[n];
    for(int i = 0; i < n; i++)  cin >> d[i];

    int dp[n+1];
    for(int i = 1; i <= n; i++)  dp[i] = INF;
    dp[0] = 0;

    int c;
    for(int i = 0; i < m; i++){
        cin >> c;
        for(int j = n-1; j >= 0; j--){
            if(dp[j] == INF)    continue;
            dp[j+1] = min(dp[j+1], dp[j] + d[j]*c);
        }
    }

    cout << dp[n] << endl;

    return 0;
}