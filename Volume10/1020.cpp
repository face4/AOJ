#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

int col(char x){
    if(x == 'A' || x == 'D' || x == 'G')    return 0;
    if(x == 'B' || x == 'E' || x == 'H')    return 1;
    return 2;
}

int row(char x){
    if(x <= 'C')    return 0;
    if(x <= 'F')    return 1;
    return 2;
}

int main(){
    int n;
    char s, t, b;
    while(cin >> n, n){
        cin >> s >> t >> b;

        vector<vector<int>> mat(3, vector<int>(3, 0));
        vector<vector<double>> ans(3, vector<double>(3, 0.0)); 
        mat[row(b)][col(b)] = 1;
        ans[row(s)][col(s)] = 1.0;

        while(n-- > 0){
            vector<vector<double>> next(3, vector<double>(3, 0.0)); 
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(ans[i][j] == 0.0)  continue;
                    for(int k = 0; k < 4; k++){
                        int di = i+dx[k], dj = j+dy[k];
                        if(!inRange(di, 0, 3) || !inRange(dj, 0, 3) || mat[di][dj]==1){
                            next[i][j] += ans[i][j]/4.0;
                        }else{
                            next[di][dj] += ans[i][j]/4.0;
                        }
                    }
                }
            }
            ans = next;
        }

        cout << fixed << setprecision(10) << ans[row(t)][col(t)] << endl;
    }
    return 0;
}