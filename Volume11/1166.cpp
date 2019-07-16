#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1<<30;

int main(){
    int w, h;
    while(cin >> w >> h, w+h){
        int mat[2*h-1][w];
        for(int i = 0; i < 2*h-1; i++){
            for(int j = 0; j < w-((i+1)%2); j++){
                cin >> mat[i][j];
            }
        }
        vector<vector<int>> dp(h, vector<int>(w, INF));
        dp[0][0] = 1;
        queue<pair<int,int>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto p = pq.front();    pq.pop();
            int i = p.first, j = p.second;
            // north
            if(i != 0 && mat[2*i-1][j] == 0 && dp[i][j]+1 < dp[i-1][j]){
                dp[i-1][j] = dp[i][j]+1;    pq.push({i-1, j});
            }
            // south
            if(i != h-1 && mat[2*(i+1)-1][j] == 0 && dp[i][j]+1 < dp[i+1][j]){
                dp[i+1][j] = dp[i][j]+1;    pq.push({i+1, j});
            }
            // west
            if(j != 0 && mat[2*i][j-1] == 0 && dp[i][j]+1 < dp[i][j-1]){
                dp[i][j-1] = dp[i][j]+1;    pq.push({i, j-1});
            }
            // east
            if(j != w-1 && mat[2*i][j] == 0 && dp[i][j]+1 < dp[i][j+1]){
                dp[i][j+1] = dp[i][j]+1;    pq.push({i, j+1});
            }
        }
        cout << (dp[h-1][w-1]==INF ? 0 : dp[h-1][w-1]) << endl;
    }
    return 0;
}