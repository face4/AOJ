#include<iostream>
#include<vector>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

inline int dist(int si, int sj, int gi, int gj){
    return abs(si-gi)+abs(sj-gj);
}

const int INF = 1<<30;

int main(){
    int w, h;
    while(cin >> w >> h, w+h){
        vector<pair<int,int>> vp[5];
        int si, sj, gi, gj;
        char mat[h][w];
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> mat[i][j];
                if(mat[i][j] == 'S')    si = i, sj = j;
                if(mat[i][j] == 'G')    gi = i, gj = j;
                if(inRange(mat[i][j],'1','5')){
                    vp[mat[i][j]-'1'].push_back({i,j});
                }
            }
        }
        int ans = -1, score = INF;
        for(int i = 0; i < 5; i++){
            vector<vector<int>> dp(4, vector<int>(1000,INF));
            for(int j = 0; j < vp[(i+1)%5].size(); j++){
                dp[0][j] = dist(si,sj,vp[(i+1)%5][j].first,vp[(i+1)%5][j].second);
            }
            for(int j = 0; j < 3; j++){
                int from = (i+1+j)%5, to = (i+1+j+1)%5;
                for(int k = 0; k < vp[from].size(); k++){
                    for(int l = 0; l < vp[to].size(); l++){
                        dp[j+1][l] = min(dp[j+1][l], dp[j][k]+dist(vp[from][k].first, vp[from][k].second, vp[to][l].first, vp[to][l].second));
                    }
                }
            }
            int tmp = INF;
            for(int j = 0; j < vp[(i+4)%5].size(); j++){
                tmp = min(tmp, dp[3][j] + dist(vp[(i+4)%5][j].first, vp[(i+4)%5][j].second, gi, gj));
            }
            if(score > tmp){
                score = tmp;
                ans = i;
            }
        }
        if(score == INF)    cout << "NA" << endl;
        else                cout << ans+1 << " " << score << endl;
    }
    return 0;
}