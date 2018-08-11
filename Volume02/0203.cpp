#include<iostream>
using namespace std;

int main(){
    int x, y;
    while(1){
        cin >> x >> y;
        if(x == 0 && y == 0)    break;
    
        int dp[y+2][x];
        char mat[y+2][x];
        for(int i = 0; i < y+2; i++){
            for(int j = 0; j < x; j++){
                dp[i][j] = 0;
                mat[i][j] = '0';
            }
        }

        for(int i = 0; i < y; i++){
            for(int j = 0; j < x; j++){
                cin >> mat[i][j];
            }
        }

        for(int j = 0; j < x; j++){
            if(mat[0][j] == '0')    dp[0][j] = 1;
        }

        for(int i = 0; i < y-1; i++){
            for(int j = 0; j < x; j++){
                if(mat[i][j] == '0'){
                    if(j != 0 && mat[i+1][j-1] == '0')      dp[i+1][j-1] += dp[i][j];
                    if(mat[i+1][j] != '1')                  dp[i+1][j] += dp[i][j];
                    if(j != x-1 && mat[i+1][j+1] == '0')    dp[i+1][j+1] += dp[i][j];
                }else if(mat[i][j] == '1'){
                    // do nothing.
                }else if(mat[i][j] == '2'){
                    dp[i+2][j] += dp[i][j];
                }
            }
        }

        int accum = 0;
        for(int j = 0; j < x; j++)  if(mat[y-1][j] != '1')  accum += dp[y-1][j];
        for(int j = 0; j < x; j++)  accum += dp[y][j];
        cout << accum << endl;
    }
    return 0;
}