// 面倒
#include<iostream>
#include<vector>
using namespace std;

int rot[6][4] = {
    {1, 2, 4, 3},
    {2, 0, 3, 5},
    {0, 1, 5, 4},
    {4, 5, 1, 0},
    {5, 3, 0, 2},
    {3, 4, 2, 1}
};

int main(){
    int n;
    while(cin >> n, n){
        string die[n][6];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 6; j++){
                cin >> die[i][j];
            }
        }
        vector<bool> ng(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int k;
                for(k = 0; k < 6; k++)  if(die[i][0] == die[j][k])  break;
                for(int kaiten = 0; kaiten < 4; kaiten++){
                    bool cw = true;
                    for(int l = 0; l < 4; l++){
                        cw &= die[i][rot[0][l]] == die[j][rot[k][(kaiten+l)%4]];
                    }
                    if(cw){
                        ng[j] = true;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)  ans += ng[i];
        cout << ans << endl;
    }
    return 0;
}