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

    int ans[h][w];
    for(int i = 0; i < h; i++){
        int cloud = -1;
        for(int j = 0; j < w; j++){
            if(cloud != -1) cloud++;
            if(mat[i][j] == 'c')    cloud = 0;
            ans[i][j] = cloud;
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << ans[i][j] << " \n"[j == w-1];
        }
    }
    
    return 0;
}