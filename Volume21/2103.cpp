#include<iostream>
#include<map>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int main(){
    int t;
    cin >> t;

    map<char,int> wj, wi;
    wj['^'] = 0; wi['^'] = -1;
    wj['U'] = 0; wi['U'] = -1;
    wj['v'] = 0; wi['v'] = +1;
    wj['D'] = 0; wi['D'] = +1;
    wj['<'] = -1; wi['<'] = 0;
    wj['L'] = -1; wi['L'] = 0;
    wj['>'] = +1; wi['>'] = 0;
    wj['R'] = +1; wi['R'] = 0;

    map<char,char> enc;
    enc['D'] = 'v';
    enc['U'] = '^';
    enc['L'] = '<';
    enc['R'] = '>';

    while(t-- > 0){
        int h, w;
        cin >> h >> w;

        char mat[h][w];
        int ri, rj, di, dj;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> mat[i][j];
                if(wj.count(mat[i][j])) ri = i, rj = j, di = wi[mat[i][j]], dj = wj[mat[i][j]];
            }
        }

        int n;
        string s;
        cin >> n >> s;

        for(char op : s){
            if(op != 'S'){
                di = wi[op], dj = wj[op];
                int ni = ri+di, nj = rj+dj;
                if(inRange(ni, 0, h) && inRange(nj, 0, w) && mat[ni][nj] == '.'){
                    mat[ri][rj] = '.';
                    ri = ni, rj = nj;
                    mat[ri][rj] = enc[op];
                }else{
                    mat[ri][rj] = enc[op];
                }
            }else{
                int si = ri+di, sj = rj+dj;
                while(inRange(si, 0, h) && inRange(sj, 0, w)){
                    if(mat[si][sj] == '*'){
                        mat[si][sj] = '.';
                        break;
                    }
                    if(mat[si][sj] == '#'){
                        break;
                    }
                    si += di, sj += dj;
                }
            }
        }

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cout << mat[i][j];
            }
            cout << endl;
        }

        if(t)   cout << endl;
    }

    return 0;
}
