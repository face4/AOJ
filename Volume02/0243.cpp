#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

struct board{
    int y, x;
    vector<vector<char>> v;
    board(int i, int j) : y(i), x(j) {
        v.resize(i, vector<char>(j));
    }
};

bool check(vector<vector<char>> v, int siz){
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cnt += (v[i][j] == v[0][0]);
        }
    }
    return cnt == siz;
}

int main(){
    int x, y;
    while(cin >> x >> y, x+y){
        char mat[y][x];
        board ini(y, x);
        for(int i = 0; i < y; i++){
            for(int j = 0; j < x; j++){
                cin >> mat[i][j];
                ini.v[i][j] = mat[i][j];
            }
        }

        queue<pair<int, board>> q;
        q.push({0, ini});

        int ans = -1;
        while(ans == -1 && !q.empty()){
            auto p = q.front(); q.pop();
            
            if(check(p.second.v, x*y)){
                ans = p.first;
                break;
            }

            for(int i = 0; i < 3; i++){
                char from = p.second.v[0][0], to = "RGB"[i];
                if(from == to)    continue;
                board next = p.second;
                queue<pair<int,int>> pq;
                pq.push({0,0});
                while(!pq.empty()){
                    pair<int,int> now = pq.front(); pq.pop();
                    if(next.v[now.first][now.second] == to) continue;
                    next.v[now.first][now.second] = to;
                    for(int k = 0; k < 4; k++){
                        int ni = now.first + dx[k], nj = now.second + dy[k];
                        if(inRange(ni, 0, y) && inRange(nj, 0, x) && next.v[ni][nj] == from){
                            pq.push({ni,nj});
                        }
                    } 
                }

                if(check(next.v, x*y)){
                    ans = p.first+1;
                    break;
                }
                q.push({p.first+1, next});
            }
        }

        cout << ans << endl;
    }
    return 0;
}