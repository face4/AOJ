#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

const int INF = 1<<30;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        char mat[m][n];
        int si, sj;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
                if(mat[i][j]=='&')  mat[i][j] = '.', si = i, sj = j;
            }
        }
        vector<vector<bool>> visit(m, vector<bool>(n, 0));
        vector<vector<int>> d(m, vector<int>(n, INF));
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{si,sj}});
        while(!pq.empty()){
            auto p = pq.front();    pq.pop();
            int cost = p.first, i = p.second.first, j = p.second.second;
            if(d[i][j] <= cost)   continue;
            d[i][j] = cost;
            for(int k = 0; k < 4; k++){
                int ni = i+di[k], nj = j+dj[k];
                if(!inRange(ni,0,m)||!inRange(nj,0,n))  continue;
                int ncost = cost + (mat[i][j]=='.'&&mat[ni][nj]=='#');
                if(d[ni][nj] > ncost)   pq.push({ncost,{ni,nj}});
            }
        }
        int ans = 1<<30;
        for(int i = 0; i < m; i++)  ans = min({ans, d[i][0], d[i][n-1]});
        for(int j = 0; j < n; j++)  ans = min({ans, d[0][j], d[m-1][j]});
        cout << ans << endl;
    }
    return 0;
}