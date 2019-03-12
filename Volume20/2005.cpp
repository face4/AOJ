#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 1<<25;

int main(){
    int n, m, s, g1, g2, a, b, c;
    while(cin >> n >> m >> s >> g1 >> g2, n+m+s+g1+g2){
        vector<vector<int>> v(n, vector<int>(n, INF));
        for(int i = 0; i < n; i++)  v[i][i] = 0;
        s--, g1--, g2--;
        while(m-- > 0){
            cin >> a >> b >> c;
            v[--a][--b] = c;
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(v[i][k]==INF || v[k][j]==INF)    continue;
                    v[i][j] = min(v[i][j], v[i][k]+v[k][j]);
                }
            }
        }
        int ans = 1<<30;
        for(int i = 0; i < n; i++){
            ans = min(ans, v[s][i]+v[i][g1]+v[i][g2]);
        }
        cout << ans << endl;
    }
    return 0;
}