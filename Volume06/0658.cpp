#include<iostream>
using namespace std;
typedef long long ll;

char mat[3001][3001];
int bot[3001][3001] = {}, rig[3001][3001] = {};

int main(){
    int h, w;
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }
    for(int i = h-1; i >= 0; i--){
        for(int j = 0; j < w; j++){
            bot[i][j] = bot[i+1][j]+(mat[i][j]=='I');
        }
    }
    for(int j = w-1; j >= 0; j--){
        for(int i = 0; i < h; i++){
            rig[i][j] = rig[i][j+1]+(mat[i][j]=='O');
        }
    }
    ll ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mat[i][j]=='J')  ans += bot[i][j]*rig[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}