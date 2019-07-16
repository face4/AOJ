#include<iostream>
#include<vector>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int di[4] = {-1, 0, 1, 0};
int dj[4] = { 0, 1, 0,-1};

int d[4] = {1, 0, -1, 2};

int main(){
    int w, h;
    while(cin >> w >> h, w+h){
        char mat[h][w];
        for(int i = 0; i < h*w; i++)    cin >> mat[i/w][i%w];
        int people = 0;
        vector<vector<int>> v(h, vector<int>(w, -1));
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(mat[i][j]=='N')  people++, mat[i][j]='.', v[i][j] = 0;
                if(mat[i][j]=='E')  people++, mat[i][j]='.', v[i][j] = 1;
                if(mat[i][j]=='S')  people++, mat[i][j]='.', v[i][j] = 2;
                if(mat[i][j]=='W')  people++, mat[i][j]='.', v[i][j] = 3;
            }
        }
        int tim = 0;
        while(++tim <= 180){
            vector<vector<int>> next(h, vector<int>(w, -1));

            // change direction
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    if(v[i][j] == -1)   continue;
                    for(int k = 0; k < 4; k++){
                        int dir = (v[i][j]+d[k]+4)%4;   // change direction(try)
                        int ni = i+di[dir], nj = j+dj[dir]; // move forward(try)
                        if(inRange(ni,0,h)&&inRange(nj,0,w)&&v[ni][nj]==-1&&mat[ni][nj]!='#'){
                            v[i][j] = dir;  // change direction(decide!)
                            break;
                        }
                    }
                }
            }
            
            // move
            for(int k = 3; k >= 0; k--){
                for(int i = 0; i < h; i++){
                    for(int j = 0; j < w; j++){
                        if(v[i][j] != k)    continue;
                        int ni = i + di[k], nj = j + dj[k];
                        if(inRange(ni,0,h)&&inRange(nj,0,w)&&mat[ni][nj]!='#'&&v[ni][nj]==-1&&next[ni][nj]==-1){
                            next[ni][nj] = v[i][j];
                            v[i][j] = -2;
                            continue;
                        }
                    }
                }
            }

            // move(stupid)
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    if(v[i][j] != -1 && v[i][j] != -2)   next[i][j] = v[i][j];
                }
            }
            
            // vanish
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    if(mat[i][j]=='X'&&next[i][j]!=-1){
                        next[i][j] = -1;
                        people--;
                    }
                }
            }
            
            v = next;
            if(people == 0) break;
        }

        if(tim > 180)   cout << "NA" << endl;
        else            cout << tim << endl;
    }
    return 0;
}
