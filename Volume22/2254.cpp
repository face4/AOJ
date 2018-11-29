#include<iostream>
#include<cstring>
using namespace std;

const int INF = 1<<28;

int main(){
    int n;
    while(cin >> n, n){
        int t[n][n+1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n+1; j++){
                cin >> t[i][j];
            }
        }
        
        int dp[1<<n];
        for(int i = 0; i < 1<<n; i++)   dp[i] = INF;
        dp[0] = 0;

        for(int s = 0; s < 1<<n; s++){
            for(int i = 0; i < n; i++){
                if(1<<i & s) continue;
                int cost = t[i][0];
                for(int j = 0; j < n; j++){
                    if(1<<j & s)    cost = min(cost, t[i][j+1]);
                }
                dp[s|(1<<i)] = min(dp[s|(1<<i)], dp[s] + cost);
            }
        }

        cout << dp[(1<<n)-1] << endl;
    }
    return 0;
}