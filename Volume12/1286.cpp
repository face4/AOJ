#include<iostream>
#include<vector>
#include<iomanip>
#include<numeric>
using namespace std;
typedef long long ll;

int main(){
    int n, m, k;
    while(cin >> n >> m >> k, n+m+k){
        vector<vector<double>> v(2, vector<double>(n*m+1, 0));
        for(int j = 0; j <= n*m; j++)   v[1][j] = 1.0;
        for(int i = 0; i < n; i++){
            v[i%2][0] = 0;
            for(int j = 1; j <= n*m; j++){
                v[i%2][j] = (v[(i+1)%2][j-1]-(j-1-m >= 0 ? v[(i+1)%2][j-1-m] : 0))/m;
                v[i%2][j] += v[i%2][j-1];
            }
        }
        double ans = 0;
        for(int j = 1; j <= n*m; j++)   ans += (v[(n+1)%2][j]-v[(n+1)%2][j-1]) * max(j-k, 1);
        cout << fixed << setprecision(12) << ans << endl;
    }
    return 0;
}