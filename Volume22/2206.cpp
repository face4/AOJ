#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        char mat[12][6];
        for(int i = 0; i < 12; i++) for(int j = 0; j < 6; j++)  cin >> mat[i][j];
        int ans = 0;
        queue<pair<int,int>> q;
        while(1){
            bool see[12][6] = {}, del[12][6] = {}, erase = false;
            for(int i = 0; i < 12; i++){
                for(int j = 0; j < 6; j++){
                    if(mat[i][j]=='.' || mat[i][j]=='O' || see[i][j])   continue;
                    vector<pair<int,int>> tmp;
                    q.push({i,j});
                    while(!q.empty()){
                        auto p = q.front(); q.pop();
                        if(see[p.first][p.second])  continue;
                        tmp.push_back(p);
                        see[p.first][p.second] = true;
                        for(int k = 0; k < 4; k++){
                            int ni = p.first + di[k], nj = p.second + dj[k];
                            if(inRange(ni,0,12)&&inRange(nj,0,6)&&!see[ni][nj]&&mat[ni][nj]==mat[i][j]){
                                q.push({ni,nj});
                            }
                        }
                    }
                    if(tmp.size() < 4)  continue;
                    erase = true;
                    for(pair<int,int> p : tmp){
                        del[p.first][p.second] = true;
                        for(int k = 0; k < 4; k++){
                            int ni = p.first+di[k], nj = p.second+dj[k];
                            if(inRange(ni,0,12)&&inRange(nj,0,6)&&mat[ni][nj]=='O') del[ni][nj] = true;
                        }
                    }
                }
            }
            if(!erase)  break;
            for(int i = 0; i < 12; i++){
                for(int j = 0; j < 6; j++){
                    if(del[i][j])   mat[i][j] = '.';
                }
            }
            for(int i = 11; i >= 0; i--){
                for(int j = 0; j < 6; j++){
                    if(mat[i][j] == '.')    continue;
                    int cp = i;
                    while(cp+1 < 12 && mat[cp+1][j]=='.')   swap(mat[cp][j], mat[cp+1][j]), cp++;
                }
            }
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
