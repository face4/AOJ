#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int dp[2001] = {};

    vector<int> v[11];
    int c, g;
    
    for(int i = 0; i < n; i++){
        cin >> c >> g;
        v[g].push_back(c);
    }

    for(int i = 1; i <= 10; i++)    sort(v[i].rbegin(), v[i].rend());

    for(int i = 1; i <= 10; i++){
        for(int j = n; j > 0; j--){
            if(dp[j] == 0) continue;
            int sum = 0;
            for(int k = 0; k < v[i].size(); k++){
                sum += v[i][k] + 2*k;
                dp[j+(k+1)] = max(dp[j+(k+1)], dp[j] + sum);
            }
        }
        
        int sum = 0;
        for(int k = 0; k < v[i].size(); k++){
            sum += v[i][k] + 2*k;
            dp[(k+1)] = max(dp[(k+1)], sum);
        }
    }
    
    cout << dp[k] << endl;

    return 0;
}