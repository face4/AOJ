#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

int main(){
    int n, w, h, x, y, s, t;
    while(cin >> n, n){
        cin >> w >> h;
        int mat[h+1][w+1];
        memset(mat, 0, sizeof(mat));
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            mat[y][x]++;
        }
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                mat[i][j] += mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
            }
        }
        cin >> s >> t;
        int ans = 0;
        for(int i = t; i <= h; i++){
            for(int j = s; j <= w; j++){
                ans = max(ans, mat[i][j]-mat[i][j-s]-mat[i-t][j]+mat[i-t][j-s]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}