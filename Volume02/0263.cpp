#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int popcnt[1<<16] = {};
int dp[31][1<<16], a[31], b[31];
bool valid[31][1<<16];

int main(){
    vector<int> popcnt(1<<16, 0);
    for(int i = 1; i < 1<<16; i++){
        for(int j = 0; j < 16; j++) popcnt[i] += (i>>j)&1;
    }
    int n, c;
    while(cin >> n >> c, n+c){
        memset(dp, 0, sizeof(dp));
        memset(valid, 0, sizeof(valid));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        valid[0][0] = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 16; j++){
                int x;  cin >> x;
                a[i] += (1<<j)*x;
            }
        }
        for(int i = 0; i < c; i++){
            for(int j = 0; j < 16; j++){
                int x;  cin >> x;
                b[i] += (1<<j)*x;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 1<<16; j++){
                if(!valid[i][j])    continue;
                int nj = j|a[i];
                for(int k = 0; k < c; k++){
                    valid[i+1][~b[k]&nj] = true;
                    dp[i+1][~b[k]&nj] = max(dp[i+1][~b[k]&nj], dp[i][j]+popcnt[nj&b[k]]);
                }
            }
        }
        int ans = 0;
        for(int j = 0; j < 1<<16; j++){
            if(valid[n][j]) ans = max(ans, dp[n][j]);
        }
        cout << ans << endl;
    }
    return 0;
}