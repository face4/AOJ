#include<iostream>
#include<map>
using namespace std;

// 前々日に何を食べたか、前日に何を食べたか、何日目か
int dp[3][3][101] = {};

int main(){
    int n, k;
    cin >> n >> k;
    map<int,int> m;
    int a, b;

    while(k--){
        cin >> a >> b;
        m[a] = b-1;
    }

    // 2日目までの予定を入れてしまう
    for(int first = 0; first < 3; first++){
        if(m.count(1) && m[1] != first) continue;
        for(int second = 0; second < 3; second++){
            if(m.count(2) && m[2] != second)    continue;
            dp[first][second][2] = 1;
        }
    }

    for(int i = 3; i <= n; i++){
        for(int today = 0; today < 3; today++){
            if(m.count(i) && m[i] != today) continue;
            for(int a = 0; a < 3; a++){
                for(int b = 0; b < 3; b++){
                    if(a == b && b == today)    continue;
                    dp[b][today][i] += dp[a][b][i-1];
                    dp[b][today][i] %= 10000;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            ans += dp[i][j][n];
            ans %= 10000;
        }
    }

    cout << ans << endl;

    return 0;
}