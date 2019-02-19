#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(m, vector<int>(n+1, 0));
    vector<int> dp(1<<m, n+1), v(n);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i]--;
        s[v[i]][i+1]++;
    }
    for(int i = 0; i < m; i++){
        for(int j = 1; j <= n; j++){
            s[i][j] += s[i][j-1];
        }
    }
    for(int t = 1; t < 1<<m; t++){
        for(int j = 0; j < m; j++){
            if(((t>>j)&1) == 0)   continue;
            int cnt = 0;
            for(int k = 0; k < m; k++){
                if(j == k)  continue;
                if((t>>k)&1)    cnt += s[k][n];
            }
            dp[t] = min(dp[t], dp[t-(1<<j)] + s[j][n]-(s[j][cnt+s[j][n]]-s[j][cnt]));
        }
    }
    cout << dp[(1<<m)-1] << endl;
    return 0;
}