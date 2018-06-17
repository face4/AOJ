// 0-1 knapsack
#include<iostream>
#include<cstring>
using namespace std;

const int INF = (1<<21);

int main(){
    int w[7] = {0, 2, 3, 5, 10, 12, 15};
    int c[7] = {0, 380, 550, 850, 1520, 1870, 2244};

    int dp[7][51] = {};
    for(int i = 0; i < 7; i++){
        for(int j = 1; j < 51; j++){
            dp[i][j] = INF;
        }
    }

    for(int i = 1; i < 7; i++){
        for(int j = 1; j <= 50; j++){
            if(w[i] > j)    dp[i][j] = dp[i-1][j];
            else            dp[i][j] = min(dp[i-1][j], dp[i][j-w[i]]+c[i]); 
        }
    }

    int kg;
    while(cin >> kg){
        if(kg == 0) break;
        cout << dp[6][kg/100] << endl;
    }

    return 0;
}