#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int INF = 1e7;
typedef long long ll;

int main(){
    int n, K;
    cin >> n >> K;
    vector<int> ax(n), ay(n), az(n), bx(n), by(n), bz(n), x, y, z;
    for(int i = 0; i < n; i++){
        cin >> ax[i] >> ay[i] >> az[i] >> bx[i] >> by[i] >> bz[i];
        x.push_back(ax[i]), x.push_back(bx[i]);
        y.push_back(ay[i]), y.push_back(by[i]);
        z.push_back(az[i]), z.push_back(bz[i]);
    }
    x.push_back(-INF), x.push_back(INF);
    y.push_back(-INF), y.push_back(INF);
    z.push_back(-INF), z.push_back(INF);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    y.erase(unique(y.begin(),y.end()),y.end());
    z.erase(unique(z.begin(),z.end()),z.end());
    int xn = x.size(), yn = y.size(), zn = z.size();
    int imos[xn][yn][zn];
    memset(imos, 0, sizeof(imos));
    for(int i = 0; i < n; i++){
        int ix = lower_bound(x.begin(),x.end(),ax[i])-x.begin();
        int iy = lower_bound(y.begin(),y.end(),ay[i])-y.begin();
        int iz = lower_bound(z.begin(),z.end(),az[i])-z.begin();
        int jx = lower_bound(x.begin(),x.end(),bx[i])-x.begin();
        int jy = lower_bound(y.begin(),y.end(),by[i])-y.begin();
        int jz = lower_bound(z.begin(),z.end(),bz[i])-z.begin();
        imos[ix][iy][iz]++;
        imos[ix][jy][iz]--;
        imos[jx][iy][iz]--;
        imos[jx][jy][iz]++;
        imos[ix][iy][jz]--;
        imos[ix][jy][jz]++;
        imos[jx][iy][jz]++;
        imos[jx][jy][jz]--;
    }

    for(int k = 0; k < zn; k++){
        for(int j = 0; j < yn; j++){
            for(int i = 1; i < xn; i++){
                imos[i][j][k] += imos[i-1][j][k];
            }
        }
    }
    for(int k = 0; k < zn; k++){
        for(int i = 0; i < xn; i++){
            for(int j = 1; j < yn; j++){
                imos[i][j][k] += imos[i][j-1][k];
            }
        }
    }
    for(int i = 0; i < xn; i++){
        for(int j = 0; j < yn; j++){
            for(int k = 1; k < zn; k++){
                imos[i][j][k] += imos[i][j][k-1];
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i < xn; i++){
        for(int j = 0; j < yn; j++){
            for(int k = 0; k < zn; k++){
                if(imos[i][j][k] < K)   continue;
                ans += (ll)(x[i+1]-x[i])*(y[j+1]-y[j])*(z[k+1]-z[k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}