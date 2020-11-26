#include<iostream>
#include<vector>
#include<list>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

typedef pair<int,int> pii;

// 0-1 bfs
int main(){
    int w, h;
    while(cin >> w >> h, w+h){
        int si, sj, gi, gj, bi, bj;
        int mat[h][w];
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> mat[i][j];
                if(mat[i][j] == 2)  mat[i][j] = 0, bi = i, bj = j;
                if(mat[i][j] == 3)  gi = i, gj = j;
                if(mat[i][j] == 4)  si = i, sj = j;
            }
        }
        vector<vector<int>> d(h*w, vector<int>(h*w, 1<<30));
        list<pair<int,pii>> q;
        q.push_front({0, {si*w+sj, bi*w+bj}});
        d[si*w+sj][bi*w+bj] = 0;
        while(!q.empty()){
            auto p = q.front(); q.pop_front();
            if(d[p.second.first][p.second.second] != p.first)    continue;
            si = p.second.first/w, sj = p.second.first%w;
            bi = p.second.second/w, bj = p.second.second%w;
            for(int k = 0; k < 4; k++){
                int ni = si+di[k], nj = sj+dj[k];
                if(!inRange(ni,0,h)||!inRange(nj,0,w)||mat[ni][nj]==1)  continue;
                if(ni==bi&&nj==bj){
                    int nbi = bi+di[k], nbj = bj+dj[k];
                    if(!inRange(nbi,0,h)||!inRange(nbj,0,w)||mat[nbi][nbj]==1)  continue;
                    if(d[ni*w+nj][nbi*w+nbj] > d[si*w+sj][bi*w+bj]+1){
                        d[ni*w+nj][nbi*w+nbj] = d[si*w+sj][bi*w+bj]+1;
                        q.push_back({d[ni*w+nj][nbi*w+nbj], {ni*w+nj, nbi*w+nbj}});                        
                    }
                }else if(d[ni*w+nj][bi*w+bj] > d[si*w+sj][bi*w+bj]){
                    d[ni*w+nj][bi*w+bj] = d[si*w+sj][bi*w+bj];
                    q.push_front({d[ni*w+nj][bi*w+bj], {ni*w+nj, bi*w+bj}});
                }
            }
        }
        int ans = 1<<30;
        for(int i = 0; i < h*w; i++){
            ans = min(ans, d[i][gi*w+gj]);
        }
        cout << (ans==1<<30 ? -1 : ans) << endl;
    }
    return 0;
}