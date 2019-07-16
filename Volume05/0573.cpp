#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define inRange(x,a,b) (a < x && x < b)

int main(){
    int n, t, s;
    cin >> n >> t >> s;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)  cin >> a[i] >> b[i];
    vector<vector<int>> dp(n+1, vector<int>(t+1, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= t-b[i]; j++){
            if(inRange(s, j, j+b[i]))   continue;
            dp[i+1][j+b[i]] = max(dp[i+1][j+b[i]], dp[i][j]+a[i]);
        }
        for(int j = 1; j <= t; j++) dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
    return 0;
}