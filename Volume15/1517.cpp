#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};
#define inRange(x,a,b) (a <= x && x < b)

void rot(int r, int c, int x, vector<vector<bool>> &v){
    vector<vector<bool>> next = v;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            next[r+i][c+j] = v[r+x-1-j][c+i];
        }
    }
    v = next;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;  cin >> x;
            a[i][j] = (x==1);
        }
    }
    int r, c, x, ang;
    while(m--){
        int op;
        cin >> op;
        if(op == 0){
            cin >> r >> c >> x >> ang;
            r--, c--;
            ang /= 90;
            while(ang--){
                rot(r, c, x, a);
            }
        }else if(op == 1){
            cin >> r >> c >> x;
            r--, c--;
            for(int i = 0; i < x; i++){
                for(int j = 0; j < x; j++){
                    a[r+i][c+j] = !a[r+i][c+j];
                }
            }
        }else if(op == 2){
            cin >> r;
            r--;
            vector<bool> tmp = a[r];
            for(int j = 0; j < n; j++)  a[r][j] = tmp[(j+1)%n];
        }else if(op == 3){
            cin >> r;
            r--;
            vector<bool> tmpb = a[r];
            for(int j = 0; j < n; j++)  a[r][j] = tmpb[(j+n-1)%n];
        }else if(op == 4){
            cin >> r >> c;
            r--, c--;
            vector<vector<bool>> b(n, vector<bool>(n,0));
            int cp = a[r][c];
            queue<int> q;
            q.push(r*n+c);
            while(!q.empty()){
                int x = q.front();  q.pop();
                int i = x/n, j = x%n;
                b[i][j] = true;
                for(int k = 0; k < 4; k++){
                    int ni = i+di[k], nj = j+dj[k];
                    if(inRange(ni,0,n)&&inRange(nj,0,n)&&a[ni][nj]==cp&&!b[ni][nj]){
                        q.push(ni*n+nj);
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(b[i][j]) a[i][j] = !a[i][j];
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " \n"[j==n-1];
        }
    }
    return 0;
}