#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
    int h, w;
    cin >> h >> w;
    char mat[h][w];
    int si, sj, gi, gj;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            if(mat[i][j] == '@')    gi = i, gj = j;
            if(mat[i][j] == '%')    si = i, sj = j;
        }
    }
    vector<vector<int>> v(h, vector<int>(w, 1<<30));
    v[si][sj] = 0;
    queue<pair<int,int>> q;
    q.push({si,sj});
    int ans = 1<<30;
    while(!q.empty()){
        pair<int,int> p = q.front();    q.pop();
        int i = p.first, j = p.second;
        for(int k = 0; k < 4; k++){
            int ni = i+di[k], nj = j+dj[k];
            if(inRange(ni,0,h)&&inRange(nj,0,w)&&mat[ni][nj]!='#'&&v[ni][nj]==1<<30){
                v[ni][nj] = v[i][j]+1;
                if(mat[ni][nj] == '$')  ans = min(ans, v[ni][nj]);
                q.push({ni,nj});
            }
        }
    }
    cout << (v[gi][gj] < ans ? "Yes" : "No") << endl;
    return 0;
}