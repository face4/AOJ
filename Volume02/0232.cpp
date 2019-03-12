#include<iostream>
#include<vector>
using namespace std;

int main(){
    int x, y, z;
    while(cin >> x >> y >> z, x+y+z){
        vector<int> v(x);
        for(int i = 0; i < x; i++)  cin >> v[i];
        vector<int> e(y+1, 0), a(y+1, 0);
        for(int i = 0; i < z; i++){
            int n;  cin >> n;
            cin >> e[n] >> a[n];
        }
        vector<vector<double>> dp(y+1, vector<double>(5001, 0));
        dp[0][0] = 1.0;
        for(int i = 0; i < y; i++){
            for(int j = 0; j < 5001; j++){
                if(dp[i][j] == 0.0) continue;
                for(int k = 0; k < x; k++){
                    int ni = i+v[k], nj = j;
                    if(ni > y)  ni = y;
                    if(e[ni] == 1)  ni = min(y, ni+a[ni]);
                    else if(e[ni] == 2) nj += a[ni];
                    else if(e[ni] == 3) nj = max(0, nj-a[ni]);
                    dp[ni][nj] += dp[i][j] / x;
                }
            }
        }
        double ans = 0;
        for(int i = 0; i < 5001; i++)   ans += dp[y][i]*i;
        cout << (int)ans << endl;
    }
    return 0;
}