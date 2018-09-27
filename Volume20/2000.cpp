#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int x = 10, y = 10, mat[21][21] = {}, a, b;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            mat[b][a]++;
        }
        
        int m;
        cin >> m;

        char w;
        int d;
        for(int i = 0; i < m; i++){
            int dy = 0, dx = 0;
            cin >> w >> d;
            if(w == 'N')    dy = 1;
            if(w == 'S')    dy = -1;
            if(w == 'E')    dx = 1;
            if(w == 'W')    dx = -1;
            for(int j = 0; j < d; j++){
                x += dx, y += dy;
                if(mat[y][x] == 1)  n--, mat[y][x]--;
            }
        }

        if(n == 0)  cout << "Yes" << endl;
        else        cout << "No" << endl;
    }
    return 0;
}