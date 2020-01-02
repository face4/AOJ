// 誤差ゲー
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

typedef long double ld;
const ld EPS = 1e-10;

ld comb[100][51][51] = {};

int main(){
    int n, m, l;
    cin >> n >> m >> l;
    vector<ld> p(n), t(n), v(n);
    for(int i = 0; i < n; i++)  cin >> p[i] >> t[i] >> v[i], p[i]/=100.0;
    for(int i = 0; i < n; i++){
        comb[i][0][0] = 1;
        for(int j = 1; j <= m; j++){
            for(int k = 0; k <= j; k++){
                comb[i][j][k] = (k>0 ? comb[i][j-1][k-1] : 0)*p[i]+comb[i][j-1][k]*(1-p[i]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(v[i] == 0){
            cout << 0 << endl;
            continue;
        }
        ld ans = 0;
        for(int j = 0; j <= m; j++){
            ld me = l/v[i]+t[i]*j;
            ld add = comb[i][m][j];
            for(int k = 0; k < n; k++){
                if(i == k || v[k] == 0)  continue;
                ld oppo = l/v[k]+t[k]*m;
                ld tim = 0;
                int now = m;
                while(now>=0 && oppo-me > EPS){
                    tim += comb[k][m][now--], oppo -= t[k];
                }
                add *= tim;
            }
            ans += add;
        }
        cout << fixed << setprecision(12) << ans << endl;
    }
    return 0;
}