#include<iostream>
#include<cstring>
using namespace std;

bool ok[1000][1000];
int c[1000], w[1000], wsum[1000], dp[1001] = {};

int wei(int i, int j){
    return wsum[j]-(i>0 ? wsum[i-1] : 0);
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)  ok[i][i] = true;
    for(int i = 0; i < n; i++){
        cin >> c[i] >> w[i];
        wsum[i] = w[i];
        if(i)   wsum[i] += wsum[i-1];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j-i >= 0){
                if(ok[j-i][j-1] && wei(j-i, j-1) <= c[j]){
                    ok[j-i][j] = true;
                }
            }
            if(j+i < n){
                if(ok[j+1][j+i] && wei(j+1, j+i) <= c[j]){
                    ok[j][j+i] = true;
                }
            }
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ok[i][j]){
                dp[j+1] = min(dp[j+1], dp[i]+1);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}