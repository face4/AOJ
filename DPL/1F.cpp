// 価値に対して重みを最小化するナップサック
#include<iostream>
using namespace std;

typedef long long ll;
ll dp[101][10001] = {};

const ll INF = 1ll<<60;

int main(){
    int n, W;
    cin >> n >> W;

    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 10001; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    int v, w;
    for(int i = 0; i < n; i++){
        cin >> v >> w;
        for(int j = 0; j < 10001-v; j++){
            if(dp[i][j] != INF){
                dp[i+1][j+v] = min(dp[i+1][j+v], dp[i][j]+w);
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            }
        }
    }

    for(int j = 10000; j >= 0; j--){
        for(int i = 0; i <= 100; i++){
            if(dp[i][j] <= W){
                cout << j << endl;
                return 0;
            }
        }
    }
}