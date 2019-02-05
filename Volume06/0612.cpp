#include<iostream>
#include<cstring>
#include<queue>
#define inRange(x,a,b) (a <= x && x < b)

using namespace std;
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
    int h, w;
    cin >> h >> w;

    char mat[h][w];
    int arr[h][w];
    memset(arr, 0, sizeof(arr));
    queue<pair<int,pair<int,int>>> q;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mat[i][j] == '.'){
                for(int k = 0; k < 8; k++){
                    int ni = i+di[k], nj = j+dj[k];
                    if(!inRange(ni,0,h) || !inRange(nj,0,w)) continue;
                    arr[ni][nj]++;
                    if(mat[ni][nj] != '.' && mat[ni][nj]-'0' == arr[ni][nj]){
                        q.push({1, {ni,nj}});
                    }
                }
            }
        }
    }
    
    int ans = 0;
    while(!q.empty()){
        auto p = q.front(); q.pop();
        ans = p.first;
        int i = p.second.first, j = p.second.second;
        mat[i][j] = '.';
        for(int k = 0; k < 8; k++){
            int ni = i+di[k], nj = j+dj[k];
            arr[ni][nj]++;
            if(mat[ni][nj] != '.' && mat[ni][nj]-'0' == arr[ni][nj]){
                q.push({ans+1, {ni,nj}});
            }
        }
    }

    cout << ans << endl;

    return 0;
}