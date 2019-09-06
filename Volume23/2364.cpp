#include<iostream>
#include<vector>
using namespace std;

int di[4] = {0,1,0,-1};
int dj[4] = {1,0,-1,0};
#define inRange(x,a,b) (a <= x && x < b)

struct UF{
    vector<int> p;
    int n;

    UF(int siz){
        n = siz;
        p.resize(n, 0);
        for(int i = 0; i < n; i++)  p[i] = i;
    }

    int parent(int x){
        if(p[x] != x)   p[x] = parent(p[x]);
        return p[x];
    }

    bool same(int x, int y){
        return parent(x) == parent(y);
    }
    
    void unite(int x, int y){
        x = parent(x), y = parent(y);
        p[x] = y;
    }
};

int main(){
    int w, h;
    cin >> w >> h;
    int ti, tj;
    char mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 't')    ti = i, tj = j;
        }
    }
    UF uf(w*h);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mat[i][j] == '#')    continue;
            for(int k = 0; k < 2; k++){
                int ni = i+di[k], nj = j+dj[k];
                if(inRange(ni,0,h)&&inRange(nj,0,w)&&mat[ni][nj]!='#'){
                    uf.unite(i*w+j, ni*w+nj);
                }
            }
        }
    }
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        if(uf.same(0, ti*w+tj)){
            cout << i << endl;
            return 0;
        }
        if(i == n)  break;
        int si, sj;
        cin >> sj >> si;
        mat[si][sj] = '.';
        for(int k = 0; k < 4; k++){
            int ni = si+di[k], nj = sj+dj[k];
            if(inRange(ni,0,h)&&inRange(nj,0,w)&&mat[ni][nj]!='#'){
                uf.unite(si*w+sj, ni*w+nj);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}