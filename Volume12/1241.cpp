#include<iostream>
using namespace std;

void dp(){
    int dp[40000][5] = {};
    dp[0][0] = 1;

    for(int i = 1; i*i < 40000; i++){
        for(int k = 1; k <= 4; k++){
            for(int j = i*i; j < 40000; j++){
                dp[j][k] += dp[j-i*i][k-1];
            }
        }
    }

    int n;
    while(cin >> n, n)  cout << dp[n][1]+dp[n][2]+dp[n][3]+dp[n][4] << endl;
}

void brute(){
    int n;
    while(cin >> n, n){
        int cnt = 0;
        for(int i = 1; i*i <= n; i++){
            if(i*i == n)    cnt++;
            for(int j = i; j*j <= n; j++){
                if(i*i + j*j == n)  cnt++;
                for(int k = j; k*k <= n; k++){
                    if(i*i + j*j + k*k == n)    cnt++;
                    for(int l = k; l*l <= n; l++){
                        if(i*i + j*j + k*k + l*l == n)  cnt++;
                    }
                }
            }
        }
        cout << cnt << endl;
    }
}

int main(){
    // どちらでも通る
    //dp();
    //brute();
    return 0;
}