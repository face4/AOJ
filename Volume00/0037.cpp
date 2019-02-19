#include<iostream>
using namespace std;

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
string s = "RDLU";

#define inRange(x,a,b) (a <= x && x < b)

int main(){
    char mat[9][5];
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < (i%2 == 0 ? 4 : 5); j++){
            cin >> mat[i][j];
        }
    }

    int i = 0, j = 1, dir = 0;
    string ans = "R";
    
    while(1){
        if(i == 0 && j == 0)    break;
        
        if(dir % 2 == 0){
            int ti = 2*i + (dir-1);
            if(inRange(ti, 0, 9)){
                if(mat[ti][j] == '1'){
                    dir = (dir - 1 + 4)%4;
                    i += di[dir], j += dj[dir];
                    ans += s[dir];
                    continue;
                }
            }
            int tj = j - dir/2;
            if(!inRange(tj, 0, 4) || mat[2*i][tj] == '0'){
                dir = (dir + 1)%4;
            }else{
                i += di[dir], j += dj[dir];
                ans += s[dir];
            }
        }else{
            int tj = j - dir/2;
            if(inRange(tj, 0, 4)){
                if(mat[2*i][tj] == '1'){
                    dir = (dir - 1 + 4)%4;
                    i += di[dir], j += dj[dir];
                    ans += s[dir];
                    continue;
                }
            }
            int ti = 2*i + (2-dir);
            if(!inRange(ti, 0, 9) || mat[ti][j] == '0'){
                dir = (dir + 1)%4;
            }else{
                i += di[dir], j += dj[dir];
                ans += s[dir]; 
            }
        }
    }

    cout << ans << endl;

    return 0;
}