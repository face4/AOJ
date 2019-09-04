#include<iostream>
#include<cstring>
using namespace std;

int v[750][750];

int main(){
    int w, h, t, p;
    while(cin >> w >> h >> t >> p, w+h+t+p){
        int oi = 0, oj = 0;
        memset(v, 0, sizeof(v));
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                v[i][j] = 1;
            }
        }
        while(t-- > 0){
            int d, c;
            cin >> d >> c;
            if(d == 1){
                for(int add = 0; add < c; add++){
                    for(int i = oi; i < oi+h; i++){
                        v[i][oj+2*c-1-add] += v[i][oj+add];
                        v[i][oj+add] = 0;
                    }
                }
                oj += c;
            }else{
                for(int add = 0; add < c; add++){
                    for(int j = oj; j < oj+w; j++){
                        v[oi+2*c-1-add][j] += v[oi+add][j];
                        v[oi+add][j] = 0;
                    }
                }
                oi += c;
            }
        }

        while(p-- > 0){
            int x, y;
            cin >> x >> y;
            cout << v[oi+y][oj+x] << endl;
        }
    }
    return 0;
}