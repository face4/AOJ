#include<iostream>
using namespace std;

char mat[1401][1401];
int dp[1401][1401];

int main(){
    int h, w;
    cin >> h >> w;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mat[i][j] == '0'){
                dp[i+1][j+1] = min(dp[i][j], min(dp[i][j+1], dp[i+1][j]))+1;
                ans = max(ans, dp[i+1][j+1]);
            }
        }
    }

    cout << ans*ans << endl;

    return 0;
}