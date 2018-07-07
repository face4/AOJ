// 移動ベクトルという概念
// 今埋めようとしている周囲に#が1個のみならば埋める、
// そうでなければ方向転換.方向転換後1つも埋められないなら終わり

#include<iostream>
using namespace std;

int dir[4][2] = {{-1,0} , {0,1}, {1,0}, {0,-1}};
char mat[100][100];
int n;

bool ok(int x, int y){
    int count = 0;
    for(int i = 0; i < 4; i++){
        int ni = x + dir[i][0];
        int nj = y + dir[i][1];
        if(0 <= ni && ni < n && 0 <= nj && nj < n && mat[ni][nj] == '#'){
            count++;
        }
    }
    return count <= 1;
}

int main(){
    int d;
    cin >> d;

    for(int c = 0; c < d; c++){
        if(c)   cout << endl;

        cin >> n;

        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                mat[i][j] = ' ';
            }
        }

        int move = 0;

        int i = n, j = 0;
        while(1){
            int ni = i + dir[move][0];
            int nj = j + dir[move][1];

            if(0 <= ni && ni < n & 0 <= nj && nj < n && ok(ni, nj)){
                mat[ni][nj] = '#';
                i = ni;
                j = nj;
            }else{
                move = (move+1)%4;
                ni = i + dir[move][0];
                nj = j + dir[move][1];
                if(0 <= ni && ni < n & 0 <= nj && nj < n && ok(ni, nj)){
                    mat[ni][nj] = '#';
                    i = ni;
                    j = nj;
                }else{
                    break;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << mat[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}