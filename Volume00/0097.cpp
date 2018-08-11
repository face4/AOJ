// dp[i][j] := i個の異なる数を用いてjを作る通り数
// 0~100までの数それぞれを使う場合について1回だけ考察する(index-i)
// index-k は使用する数の個数

#include<iostream>
using namespace std;

long long dp[10][1000] = {};

int main(){
    dp[0][0] = 1;

    for(int i = 0; i <= 100; i++){
        for(int k = 9; k >= 1; k--){
            for(int j = 0; j+i < 1000; j++){
                dp[k][j+i] += dp[k-1][j];
            }
        }
    }
    
    int n, s;
    while(cin >> n >> s){
        if(n+s == 0)    break;
        cout << dp[n][s] << endl;
    }
    
    return 0;
}
