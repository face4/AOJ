#include<iostream>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    int mat[h][w];
    char x;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> x;
            mat[i][j] = x-'0';
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(i && j)   mat[i][j] += min(mat[i-1][j], mat[i][j-1]);
            else if(i)  mat[i][j] += mat[i-1][j];
            else if(j)  mat[i][j] += mat[i][j-1];
        }
    }
    cout << mat[h-1][w-1] << endl;
    return 0;
}