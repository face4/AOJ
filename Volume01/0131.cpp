// 最初の一行さえ決め打ちしてしまえば、あとは必然的に決まる
// 全探索2^10 * 9
#include<iostream>
#include<vector>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)
int di[5] = {0,0,1,-1,0};
int dj[5] = {1,-1,0,0,0};

int main(){
    int n;
    cin >> n;
    while(n-- > 0){
        vector<vector<int>> mat(10, vector<int>(10));
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                cin >> mat[i][j];
            }
        }
        for(int s = 0; s < 1<<10; s++){
            vector<vector<int>> cp = mat, ans(10, vector<int>(10, 0));
            for(int j = 0; j < 10; j++){
                if((s>>j)&1)    continue;
                ans[0][j] = 1;
                for(int k = 0; k < 5; k++){
                    int ni = 0+di[k], nj = j+dj[k];
                    if(inRange(ni,0,10)&&inRange(nj,0,10)){
                        cp[ni][nj] = 1-cp[ni][nj];
                    }
                }
            }
            for(int i = 1; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    if(cp[i-1][j] == 0) continue;
                    ans[i][j] = 1;
                    for(int k = 0; k < 5; k++){
                        int ni = i+di[k], nj = j+dj[k];
                        if(inRange(ni,0,10)&&inRange(nj,0,10)){
                            cp[ni][nj] = 1-cp[ni][nj];
                        }
                    }
                }
            }
            bool valid = true;
            for(int j = 0; j < 10; j++) valid &= !cp[9][j];
            if(valid){
                // answer.
                for(int i = 0; i < 10; i++){
                    for(int j = 0; j < 10; j++){
                        cout << ans[i][j] << " \n"[j==9];
                    }
                }
                break;
            }
        }
    }
    return 0;
}