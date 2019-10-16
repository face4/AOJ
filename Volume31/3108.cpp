#include<iostream>
#include<vector>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

bool ok;

void dfs(int id, int cnt, const vector<vector<vector<char>>> v, vector<vector<char>> &board){
    if(cnt == 3){
        ok = true;
        return;
    }
    if(id == 4) return;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 10; j++){
            bool put = true;
            for(int k = 0; k < v[id].size(); k++){
                for(int l = 0; l < v[id][0].size(); l++){
                    if(v[id][k][l] == '.')  continue;
                    if(!inRange(i+k,0,4) || !inRange(j+l,0,10) || board[i+k][j+l] == '#'){
                        put = false;
                        break;
                    }
                }
                if(!put)    break;
            }
            if(!put)    continue;
            for(int k = 0; k < v[id].size(); k++){
                for(int l = 0; l < v[id][0].size(); l++){
                    if(v[id][k][l] == '.')  continue;
                    board[i+k][j+l] = '#';
                }
            }
            dfs(id+1, cnt+1, v, board);
            for(int k = 0; k < v[id].size(); k++){
                for(int l = 0; l < v[id][0].size(); l++){
                    if(v[id][k][l] == '.')  continue;
                    board[i+k][j+l] = '.';
                }
            }
        }
    }

    if(3-id+cnt >= 3)   dfs(id+1, cnt, v, board);
}

int main(){
    vector<vector<vector<char>>> v;
    for(int i = 0; i < 4; i++){
        int h, w;
        cin >> h >> w;
        vector<vector<char>> tmp(h, vector<char>(w));
        for(int j = 0; j < h; j++){
            for(int k = 0; k < w; k++){
                cin >> tmp[j][k];
            }
        }
        v.push_back(tmp);
    }
    int n;
    cin >> n;
    while(n-- > 0){
        vector<vector<char>> board(4, vector<char>(10));
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 10; j++){
                cin >> board[i][j];
            }
        }
        ok = false;
        dfs(0, 0, v, board);
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}
