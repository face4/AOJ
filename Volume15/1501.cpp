#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int mod = 100000007;

struct Combination{
    int n;
    vector<vector<int>> dp;

    Combination(int i){
        n = i;
        dp = vector<vector<int>>(n+1, vector<int>(n+1, 0));
        constructTriangle();
    }

    void constructTriangle(){
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i][0] = dp[i-1][0];
            for(int j = 1; j <= i; j++){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % mod;
            }
        }
    }

    // return aCb
    int getCombination(int a, int b){
        return dp[a][b];
    }
};

int main(){
    Combination comb(1001);

    int r, c, ax, ay, bx, by;
    cin >> r >> c >> ax >> ay >> bx >> by;

    int mind = 1001;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int nx = bx + i*r, ny = by + j*c;
            mind = min(mind, abs(nx-ax) + abs(ny-ay));
        }
    }

    ll ans = 0;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int nx = bx + i*r, ny = by + j*c;
            int x = abs(nx-ax), y = abs(ny-ay);
            if(x+y != mind)   continue;
            ans += comb.getCombination(x+y, x);
            ans %= mod;
        }
    }

    cout << ans << endl;

    return 0;
}