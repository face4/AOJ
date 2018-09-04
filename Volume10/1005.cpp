#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int mat[100][100] = {};
        bool hand[100][100] = {};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }

        for(int i = 0; i < n; i++){
            int minval = 1000000;
            vector<int> minpos;
            for(int j = 0; j < n; j++){
                if(mat[i][j] < minval){
                    minval = mat[i][j];
                    minpos.clear();
                    minpos.push_back(j);
                }else if(mat[i][j] == minval){
                    minpos.push_back(j);
                }
            }
            for(int x : minpos) hand[i][x] = true;
        }

        int ans = 0;
        for(int j = 0; j < n; j++){
            int maxval = -1;
            vector<int> maxpos;
            for(int i = 0; i < n; i++){
                if(mat[i][j] > maxval){
                    maxval = mat[i][j];
                    maxpos.clear();
                    maxpos.push_back(i);
                }else if(mat[i][j] == maxval){
                    maxpos.push_back(i);
                }
            }
            for(int x : maxpos) if(hand[x][j]) ans = maxval;
        }

        cout << ans << endl;
    }
    return 0;
}