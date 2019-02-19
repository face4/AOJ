#include<iostream>
#include<set>
using namespace std;

int main(){
    int t;  cin >> t;
    while(t-- > 0){
        int gx, gy, p;
        cin >> gx >> gy >> p;
        int m[20][20][2] = {};
        while(p-- > 0){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if(a+b > c+d)   swap(a,c), swap(b,d);
            if(a == c)  m[a][b][1] = 1;
            else        m[a][b][0] = 1;
        }
        int dp[20][20] = {};
        dp[0][0] = 1;
        for(int i = 0; i <= gx; i++){
            for(int j = 0; j <= gy; j++){
                if(m[i][j][0] == 0) dp[i+1][j] += dp[i][j];
                if(m[i][j][1] == 0) dp[i][j+1] += dp[i][j];
            }
        }
        if(dp[gx][gy])  cout << dp[gx][gy] << endl;
        else            cout << "Miserable Hokusai!" << endl;
    }
    return 0;
}