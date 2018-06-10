#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int mat[n][n] = {};

    for(int i = 0; i < n; i++){
        int x, k, y;
        cin >> x >> k;
        while(k-- > 0){
            cin >> y;
            mat[x-1][y-1] = 1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j) cout << " ";
            cout << mat[i][j];
        }
        cout << endl;
    }

    return 0;
}