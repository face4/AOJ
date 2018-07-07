#include<iostream>
using namespace std;

int mat[9][9];
bool judge[9][9];

int main(){
    int n;
    cin >> n;

    for(int x = 0; x < n; x++){
        if(x)   cout << endl;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cin >> mat[i][j];
                judge[i][j] = false;
            }
        }

        // horizontal
        for(int i = 0; i < 9; i++){
            int cnt[10] = {};
            for(int j = 0; j < 9; j++){
                cnt[mat[i][j]]++;
            }
            for(int j = 0; j < 9; j++){
                if(cnt[mat[i][j]] > 1)  judge[i][j] = true;
            }
        }

        // vertital
        for(int i = 0; i < 9; i++){
            int cnt[10] = {};
            for(int j = 0; j < 9; j++){
                cnt[mat[j][i]]++;
            }
            for(int j = 0; j < 9; j++){
                if(cnt[mat[j][i]] > 1)  judge[j][i] = true;
            }
        }

        // box
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int cnt[10] = {};
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        cnt[mat[3*i + k][3*j + l]]++;
                    }
                }
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        if(cnt[mat[3*i + k][3*j + l]] > 1)
                            judge[3*i + k][3*j + l] = true;
                    }
                }
            }
        }
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(judge[i][j]) cout << "*";
                else            cout << " ";
                cout << mat[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}