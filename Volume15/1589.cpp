#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct data{
    int a, k, t;
    bool operator< (const data other) const{
        return a+k < other.a+other.k;
    }
};

int main(){
    int n, m, L, d, a, k, t;
    cin >> n >> m >> L;
    vector<data> day[5];
    while(m-- > 0){
        cin >> d >> a >> k >> t;
        day[d].push_back(data({a,k,t}));
    }
    for(int i = 0; i < 5; i++)  sort(day[i].begin(), day[i].end());
    vector<vector<vector<int>>> dp(5, vector<vector<int>>(n+1, vector<int>(n+1, 0)));
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < day[i].size(); j++){
            for(int cnt = n; cnt >= 1; cnt--){
                for(int l = day[i][j].a-1; l >= 0; l--){
                    dp[i][cnt][day[i][j].a+day[i][j].k-1] 
                    = max(dp[i][cnt][day[i][j].a+day[i][j].k-1], dp[i][cnt-1][l]+day[i][j].t);
                }
            }
        }
    }
    vector<vector<int>> dp2(5, vector<int>(n+1, 0));
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < n+1; j++){
            for(int k = 0; k < n+1; k++){
                dp2[i][j] = max(dp2[i][j], dp[i][j][k]);
            }
            if(j)   dp2[i][j] = max(dp2[i][j], dp2[i][j-1]);
        }
    }
    int ans = 0;
    for(int i = 1; i < 9*9*9*9*9; i++){
        int cp = i, tmp = 0, takes = 0;
        for(int j = 0; j < 5; j++){
            int take = min(cp%9, n);
            takes += take;
            cp /= 9;
            tmp += dp2[j][take];
        }
        if(takes <= L)  ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}