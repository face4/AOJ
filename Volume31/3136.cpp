#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int dist[22][22];
int dp[22][1<<22];
int bfs[1000][1000];
int cnt = 0;

int dec(char c){
    if(c == 's')    return 0;
    if(c == 'e')    return cnt+1;
    return c-'A'+1;
}

int main(){
    memset(dist, 0x3f, sizeof(dist));
    memset(dp, 0x3f, sizeof(dp));
    int h, w, k;
    cin >> h >> w >> k;
    char mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'a'){
                mat[i][j] = (char)('A' + cnt++);
            }
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mat[i][j] == '#' || mat[i][j] == '.')    continue;
            int ind = dec(mat[i][j]);
            memset(bfs, 0x3f, sizeof(bfs));
            bfs[i][j] = 0;
            queue<int> q;
            q.push(i*w+j);
            while(!q.empty()){
                int x = q.front();  q.pop();
                int i = x/w, j = x%w;
                if(mat[i][j] != '.'){
                    dist[ind][dec(mat[i][j])] = bfs[i][j];
                }
                for(int k = 0; k < 4; k++){
                    int ni = i+di[k], nj = j+dj[k];
                    if(inRange(ni,0,h)&&inRange(nj,0,w)&&bfs[ni][nj]>bfs[i][j]+1&&mat[ni][nj]!='#'){
                        bfs[ni][nj] = bfs[i][j]+1;
                        q.push(ni*w+nj);
                    }
                }
            }
        }
    }
    dp[0][1] = 0;
    for(int s = 1; s < 1<<(cnt+1); s++){
        for(int i = 0; i < cnt+1; i++){
            if(((s>>i)&1) == 0) continue;
            if(dp[i][s] > 1e9)  continue;
            for(int j = 0; j < cnt+1; j++){
                if((s>>j)&1)   continue;
                if(dist[i][j] > 1e9)    continue;
                dp[j][s|(1<<j)] = min(dp[j][s|(1<<j)], dp[i][s]+dist[i][j]);
            }
        }
    }
    int ret = 2e9;
    for(int s = 1; s < 1<<(cnt+1); s++){
        int pop = -1;
        for(int j = 0; j < cnt+1; j++)  pop += (s>>j)&1;
        if(pop < k) continue;
        for(int j = 1; j <= cnt; j++){
            if(dist[j][cnt+1] < 1e9 && dp[j][s] < 1e9)  ret = min(ret, dp[j][s]+dist[j][cnt+1]);
        }
    }
    cout << (ret >= 2e9 ? -1 : ret) << endl;
    return 0;
}