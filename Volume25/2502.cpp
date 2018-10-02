#include<iostream>
#include<vector>
using namespace std;

int dp[400] = {};

int main(){
    int n;
    cin >> n;

    int s, l, p;
    for(int i = 1; i <= n; i++){
        cin >> s >> l >> p;
        for(int j = 1; j <= 400; j++){
            for(int k = s; j-k >= 0 && k <= l; k++){
                dp[j] = max(dp[j], dp[j-k]+p);
            }
        }
    }

    int m;
    cin >> m;

    int w;
    vector<int> ans;
    for(int i = 0; i < m; i++){
        cin >> w;
        if(dp[w] == 0){
            cout << -1 << endl;
            return 0;
        }
        ans.push_back(dp[w]);
    }

    for(int x : ans)    cout << x << endl;
    
    return 0;
}