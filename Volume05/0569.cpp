#include<iostream>
#include<queue>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)

int di[2][6] = {{ 0,-1, 0, 1, 1,-1}, { 1,-1,-1, 0, 1, 0}};
int dj[2][6] = {{-1, 0, 1,-1, 0,-1}, { 1, 0, 1,-1, 0, 1}};

int main(){
    int w, h;
    cin >> w >> h;

    int mat[102][102] = {};
    bool outer[103][103] = {};

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> mat[i][j];
        }
    }

    // 考察の関係でiとjが滅茶苦茶になっています.
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> now = q.front();  q.pop();
        int i = now.first, j = now.second;
        if(outer[i][j]) continue;
        outer[i][j] = true;
        for(int k = 0; k < 6; k++){
            int ni = i + di[i%2][k], nj = j + dj[i%2][k];
            if(!inRange(ni, 0, h+3) || !inRange(nj, 0, w+3) || mat[ni][nj] == 1) continue;
            q.push({ni,nj});
        }
    }

    int ans = 0;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(mat[i][j] == 0)  continue;
            int wall = 0;
            for(int k = 0; k < 6; k++){
                int ni = i+di[i%2][k], nj = j+dj[i%2][k];
                if(outer[ni][nj])   wall++;
            }
            ans += wall;
        }
    }

    cout << ans << endl;

    return 0;
}