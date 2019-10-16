#include<iostream>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    char mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char c; cin >> c;
            if(c != mat[i][j])  ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
