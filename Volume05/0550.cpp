#include<iostream>
#include<cstring>
using namespace std;

int dp[2][5002][2];

int main(){
    memset(dp, 0x3f, sizeof(dp));
    int n;
    cin >> n;
    int a[n-1];
    for(int i = 0; i < n-1; i++)    cin >> a[i];
    dp[0][1][0] = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < 5001; j++)   dp[(i+1)%2][j][0] = dp[(i+1)%2][j][1] = 1<<30;
        for(int j = 1; j < 5001; j++){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){
                    int cost = k != l ? a[i] : 0;
                    int nj = j + (l==0);
                    dp[(i+1)%2][nj][l] = min(dp[(i+1)%2][nj][l], dp[i%2][j][k]+cost);
                }
            }
        }
    }
    cout << min(dp[1][n/2][0], dp[1][n/2][1]) << endl;
    return 0;
}