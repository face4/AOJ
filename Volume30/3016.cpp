#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
    int n;
    cin >> n;
    char mat[n][n];
    for(int i = 0; i < n*n; i++)    cin >> mat[i/n][i%n];
    int ret = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 'x')    continue;
            mat[i][j] = 'x';
            ret++;
            queue<int> q;
            q.push(i*n+j);
            while(!q.empty()){
                int x = q.front();  q.pop();
                int I = x/n, J = x%n;
                for(int k = 0; k < 4; k++){
                    int ni = I+di[k], nj = J+dj[k];
                    if(inRange(ni,0,n)&&inRange(nj,0,n)&&mat[ni][nj]=='o'){
                        mat[ni][nj] = 'x';
                        q.push(ni*n+nj);
                    }
                }
            }
        }
    }
    cout << (ret-1)/3 << endl;
    return 0;
}