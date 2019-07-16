#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

vector<vector<int>> mat(8, vector<int>(8));
int h, w, c, ans = 0;

void dfs(int cur){
    if(cur == 5){
        vector<vector<int>> cp = mat;
        int from = mat[0][0], to = c;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            pair<int,int> p = q.front();    q.pop();
            int i = p.first, j = p.second;
            if(mat[i][j]==to)   continue;
            mat[i][j] = to;
            for(int k = 0; k < 4; k++){
                int ni = i+di[k], nj = j+dj[k];
                if(inRange(ni,0,h)&&inRange(nj,0,w)&&mat[ni][nj]==from) q.push({ni,nj});
            }
        }
        int tmp = 0;
        vector<vector<bool>> visit(8, vector<bool>(8,0));
        q.push({0,0});
        while(!q.empty()){
            pair<int,int> p = q.front();    q.pop();
            int i = p.first, j = p.second;
            if(visit[i][j])   continue;
            visit[i][j] = true;
            tmp++;
            for(int k = 0; k < 4; k++){
                int ni = i+di[k], nj = j+dj[k];
                if(inRange(ni,0,h)&&inRange(nj,0,w)&&mat[ni][nj]==to) q.push({ni,nj});
            }
        }
        ans = max(ans, tmp);
        mat = cp;
        return;
    }

    for(int to = 1; to <= 6; to++){
        if(mat[0][0] == to) continue;
        vector<vector<int>> cp = mat;
        int from = mat[0][0];
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            pair<int,int> p = q.front();    q.pop();
            int i = p.first, j = p.second;
            if(mat[i][j]==to)   continue;
            mat[i][j] = to;
            for(int k = 0; k < 4; k++){
                int ni = i+di[k], nj = j+dj[k];
                if(inRange(ni,0,h)&&inRange(nj,0,w)&&mat[ni][nj]==from) q.push({ni,nj});
            }
        }
        dfs(cur+1);
        mat = cp;
    }

    return;
}

int main(){
    while(cin >> h >> w >> c, h+w+c){
        ans = 0;
        mat.resize(8, vector<int>(8,0));
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> mat[i][j];
            }
        }
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}