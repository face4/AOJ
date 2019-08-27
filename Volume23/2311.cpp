#include<iostream>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

char mat[8][8];
string ox = "ox";

void output(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << mat[i][j];
        }
        cout << endl;
    }
}

int num(int i, int j, int x){
    int ret = 0;
    for(int k = 0; k < 8; k++){
        int ni = i+di[k], nj = j+dj[k], cnt = 0;
        while(inRange(ni,0,8)&&inRange(nj,0,8)&&mat[ni][nj]==ox[1-x]){
            ni += di[k], nj += dj[k], cnt++;
        }
        if(inRange(ni,0,8)&&inRange(nj,0,8)&&mat[ni][nj]==ox[x]){
            ret += cnt;
        }
    }
    return ret;
}

void put(int i, int j, int x){
    for(int k = 0; k < 8; k++){
        int ni = i+di[k], nj = j+dj[k];
        while(inRange(ni,0,8)&&inRange(nj,0,8)&&mat[ni][nj]==ox[1-x]){
            ni += di[k], nj += dj[k];
        }
        if(inRange(ni,0,8)&&inRange(nj,0,8)&&mat[ni][nj]==ox[x]){
            while(ni != i || nj != j){
                ni -= di[k], nj -= dj[k];
                mat[ni][nj] = ox[x];
            }
        }
    }
}

int main(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> mat[i][j];
        }
    }
    bool update = true;
    while(update){
        update = false;
        for(int s = 0; s < 2; s++){
            int pi = -1, pj = -1, cnt = 0;
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    int gi = s==0 ? i : 7-i;
                    int gj = s==0 ? j : 7-j;
                    if(mat[gi][gj] != '.')    continue;
                    int tmp = num(gi, gj, s);
                    if(tmp > cnt)   cnt = tmp, pi = gi, pj = gj;
                }
            }
            if(cnt == 0)    continue;
            update = true;
            put(pi, pj, s);
        }
    }
    output();
    return 0;
}