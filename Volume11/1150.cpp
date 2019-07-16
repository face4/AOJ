#include<iostream>
#include<queue>
using namespace std;

const int INF = 1<<30;

// lr-0 left, lr-1 right
struct data{
    int i, j, lr, cost;
    bool operator<(const data other)const{
        return cost > other.cost;
    }
};

#define inRange(x,a,b) (a <= x && x < b)
int di[9] = {-2, -1, -1, 0, 0, 0, 1, 1, 2};
int dj[9] = {-1, -1, -2, -1, -2, -3, -1, -2, -1};

int main(){
    int w, h;
    while(cin >> w >> h, w+h){
        char mat[h][w];
        for(int i = 0; i < w*h; i++)    cin >> mat[i/w][i%w];
        int dp[2][h][w];
        for(int i = 0; i < 2; i++)  for(int j = 0; j < h; j++)  for(int k = 0; k < w; k++)  dp[i][j][k] = INF;
        priority_queue<data> pq;
        for(int j = 0; j < w; j++){
            if(mat[h-1][j] == 'S')  pq.push(data({h-1, j, 0, 0})), pq.push(data({h-1, j, 1, 0}));
        }
        int ans = 1<<30;
        while(!pq.empty()){
            data d = pq.top();  pq.pop();
            int i = d.i, j = d.j, lr = d.lr, cost = d.cost;
            if(dp[lr][i][j] <= cost)    continue;
            dp[lr][i][j] = cost;
            if(mat[i][j] == 'T'){
                ans = min(ans, dp[lr][i][j]);
                continue;
            }
            for(int k = 0; k < 9; k++){
                int ni = i+di[k], nj = j + (2*lr-1)*dj[k];
                if(inRange(ni,0,h)&&inRange(nj,0,w)&&mat[ni][nj]!='X'&&mat[ni][nj]!='S'){
                    int ncost = cost;
                    if(mat[ni][nj] != 'T')  ncost += mat[ni][nj]-'0';
                    if(dp[1-lr][ni][nj] > ncost){
                        pq.push(data({ni,nj,1-lr,ncost}));
                    }
                }
            }
        }
        if(ans == 1<<30)    ans = -1;
        cout << ans << endl;
    }
    return 0;
}