// 他人の解説を読んだ
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int dp[301][301];

int main(){
    int n;
    while(cin >> n, n){
        memset(dp, 0, sizeof(dp));
        vector<int> v(n);
        for(int i = 0; i < n; i++)  cin >> v[i];
        for(int w = 2; w <= n; w++){
            for(int i = 0; i < n; i++){
                int j = i+w-1;
                if(j >= n)  continue;
                if(dp[i+1][j-1] == w-2 && abs(v[i]-v[j]) <= 1)  dp[i][j] = dp[i+1][j-1]+2;
                for(int k = i; k < j; k++){
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]);
                }
            }
        }
        cout << dp[0][n-1] << endl;
    }
    return 0;
}