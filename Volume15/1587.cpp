#include<iostream>
using namespace std;

int mat[50][50] = {};

int main(){
    int w, h, t, p;
    cin >> w >> h >> t >> p;
    int x, y;
    while(p-- > 0){
        cin >> x >> y >> t;
        mat[y][x]++;
    }
    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> t;
            ans += t * mat[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}