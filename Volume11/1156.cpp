#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int INF = 1<<30;

struct data{
    int i, j, dir;
    bool operator<(const data other) const{return true;}
};

#define inRange(x,a,b) (a <= x && x < b)
int di[4] = {0,1,0,-1};
int dj[4] = {1,0,-1,0};

int main(){
    int w, h;
    while(cin >> w >> h, w+h){
        char mat[h][w];
        int dp[4][h][w], c[4];
        for(int i = 0; i < h*w; i++){
            cin >> mat[i/w][i%w];
            for(int j = 0; j < 4; j++)  dp[j][i/w][i%w] = INF;
        }
        for(int i = 0; i < 4; i++)  cin >> c[i];
        priority_queue<pair<int,data>> pq;
        pq.push({-0, data({0, 0, 0})});
        int ans;
        while(!pq.empty()){
            auto p = pq.top();  pq.pop();
            int cost = -p.first, i = p.second.i, j = p.second.j, dir = p.second.dir;
            if(dp[dir][i][j] <= cost)   continue;
            dp[dir][i][j] = cost;
            if(i == h-1 && j == w-1){
                ans = cost;
                break;
            }
            for(int k = 0; k < 4; k++){
                int way = (dir+k)%4;
                int ni = i+di[way], nj = j+dj[way], ncost = cost;
                if(!inRange(ni,0,h)||!inRange(nj,0,w))  continue;
                if(k != mat[i][j]-'0')    ncost += c[k];
                if(dp[way][ni][nj] > ncost)  pq.push({-ncost, data({ni,nj,way})});
            }
        }
        cout << ans << endl;
    }
    return 0;
}