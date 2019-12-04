#include<iostream>
#include<algorithm>
using namespace std;

int dp[10001][1<<4] = {}, ng[10001] = {};

int main(){
    int h, n;
    cin >> h >> n;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        ng[y] += 1<<x;
    }

    for(int i = 1; i < h; i++){
        // put 1
        for(int xj = 0; xj < 1<<4; xj++){
            int put = 12;
            while(put >= 3){
                if(((put&ng[i-1])==0) && ((xj&put)==0) && ((ng[i]&put)==0)){
                    dp[i][put|ng[i]] = max(dp[i][put|ng[i]], dp[i-1][xj]+1);
                }
                put >>= 1;
            }
        }
        // put 2
        if(ng[i-1] == 0 && ng[i] == 0){
            dp[i][(1<<4)-1] = max(dp[i][(1<<4)-1], dp[i-1][0]+2);
        }
        for(int j = 0; j < 1<<4; j++)   dp[i][0] = max(dp[i][0], dp[i-1][j]);
    }

    int ans = 0;
    for(int j = 0; j < 1<<4; j++)   ans = max(ans, dp[h-1][j]);
    cout << ans << endl;

    return 0;
}