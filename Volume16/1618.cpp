#include<iostream>
using namespace std;
#define rep(i, a, n) for(int i = (a); i < (n); i++)

int main(){
    int d, w;
    while(cin >> d >> w, d+w){
        int mat[d][w];
        for(int i = 0; i < d*w; i++)    cin >> mat[i/w][i%w];

        int ans = 0;

        rep(i, 0, d) rep(j, 0, w){
            rep(ni, i+2, d) rep(nj, j+2, w){
                int surround = 10, water = 0, lakesum = 0;
                rep(di, i, ni+1) rep(dj, j, nj+1){
                    if(di == i || di == ni || dj == j || dj == nj){
                        surround = min(surround, mat[di][dj]);
                    }else{
                        water = max(water, mat[di][dj]); 
                        lakesum += mat[di][dj];
                    }
                }

                if(surround <= water)   continue;

                int lakeA = (ni-i-1)*(nj-j-1);
                ans = max(ans, surround*lakeA - lakesum);
            }
        }

        cout << ans << endl;
    }
    return 0;
}