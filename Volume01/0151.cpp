// 一応AC.
// 他の人の回答はもっと簡潔で、i*jの全てのマスについて、それが1ならば
// そのマスを始点とした時の左水平方向、上垂直方向、左斜め上方向、右斜め上方向
// に何個1が連続しているかを数えて最大値を更新すればよい.
#include<iostream>
using namespace std;

int n;
char mat[255][255];
// vertical
int v[255][255];
// horizontal
int h[255][255];
// right-down diagonally
int rd[255][255];
// left-down diagonally
int ld[255][255];

int solve(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            v[i][j] = h[i][j] = rd[i][j] = ld[i][j] = 0;
        }
    }

    if(mat[0][0]=='1')  v[0][0] = h[0][0] = rd[0][0] = ld[0][0] = 1;

    for(int j = 1; j < n; j++){
        if(mat[0][j]=='1'){
            h[0][j] = h[0][j-1]+1;
            v[0][j] = rd[0][j] = ld[0][j] = 1;
        }  
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j]=='1'){
                if(j != 0)      h[i][j] = h[i][j-1]+1;    
                else            h[i][j] = 1;
                v[i][j] = v[i-1][j]+1;
                if(j != n-1)    ld[i][j] = ld[i-1][j+1]+1;
                else            ld[i][j] = 1;
                if(j != 0)      rd[i][j] = rd[i-1][j-1]+1;
                else            rd[i][j] = 1;
            }
        }
    }

    int ret = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ret = max(ret, max(max(max(h[i][j], v[i][j]), rd[i][j]),ld[i][j]));
        }
    }

    return ret;
}

int main(){
    while(cin >> n){
        if(n == 0)  break;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }

        cout << solve() << endl;
    }


    return 0;
}