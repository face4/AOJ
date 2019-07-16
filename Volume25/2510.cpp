#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vector<pair<int,int>> v(n);
        for(int i = 0; i < n; i++)  cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end());
        int sum = 0;
        for(int i = 0; i < n-1; i++)    sum += v[i].first;
        int ans = sum + v[n-1].first;
        for(int i = 0; i < n; i++)  ans += v[i].second;
        if(sum < v[n-1].first){
            int res = v[n-1].first - sum;
            bool dp[1001] = {};
            dp[0] = true;
            for(int i = 0; i < n-1; i++){
                for(int j = res; j >= v[i].second; j--){
                    dp[j] |= dp[j-v[i].second];
                }
            }
            int ma;
            for(ma = res; ma >= 0; ma--){
                if(dp[ma])  break;
            }
            cout << ans + res-ma << endl;
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}