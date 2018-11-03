#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int d[400][400] = {};
    int a, b, c;

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        d[a][b] = c;
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(d[i][k] == 0 || d[k][j] == 0)    continue;
                d[i][j] = max(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }

    cout << d[0][n-1] << endl;

    return 0;
}