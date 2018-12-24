#include<iostream>
#include<cstring>
using namespace std;

bool dp[1000001] = {};

int main(){
    int n, a, b;
    while(cin >> n >> a >> b, n+a+b){
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        for(int i = 0; i <= n; i++){
            if(!dp[i])  continue;
            if(i+a <= n)    dp[i+a] = true;
            if(i+b <= n)    dp[i+b] = true;
        }

        int cnt = n;
        for(int i = 1; i <= n; i++) cnt -= dp[i];

        cout << cnt << endl;
    }
    return 0;
}