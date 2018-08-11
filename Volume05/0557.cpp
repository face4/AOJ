#include<iostream>
using namespace std;

typedef long long ll;

ll dp[99][21] = {};

int main(){
    int n;
    cin >> n;

    int x;
    cin >> x;
    dp[0][x] = 1;

    for(int i = 1; i < n-1; i++){
        cin >> x;
        for(int j = 0; j <= 20; j++){
            int p = j+x, m = j-x;
            if(0 <= p && p <= 20)   dp[i][p] += dp[i-1][j];
            if(0 <= m && m <= 20)   dp[i][m] += dp[i-1][j];
        }
    }

    cin >> x;

    cout << dp[n-2][x] << endl;

    return 0;
}