#include<iostream>
#include<cstring>
using namespace std;

#define W 1000
#define N 1000

int w, n, vi, wi, maxv, maxw;
int dp[N+1][W+1];
int values[N+1];
int weights[N+1];

int main(){
    int caseNum = 1;
    while(1){
        scanf("%d", &w);
        if(w == 0)  break;

        scanf("%d\n", &n);
        memset(dp, 0, sizeof(dp));
        memset(values, 0, sizeof(values));
        memset(weights, 0, sizeof(weights));

        for(int i = 0; i < n; i++){
            scanf("%d,%d\n", &values[i+1], &weights[i+1]);
        }

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= w; j++){
                if(j >= weights[i]){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]]+values[i]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        maxv = -1;
        maxw = -1;
        for(int i = 0; i <= w; i++){
            if(maxv < dp[n][i]){
                maxv = dp[n][i];
                maxw = i;
            }
        }

        printf("Case %d:\n%d\n%d\n", caseNum, maxv, maxw);
        caseNum++;
    }
    
    return 0;
}
