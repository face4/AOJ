#include<iostream>
using namespace std;

char mat[3][3];

char judge(){
    for(int i = 0; i < 3; i++){
        if(mat[i][0] != '+' && mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2]) return mat[i][2];
        if(mat[0][i] != '+' && mat[0][i] == mat[1][i] && mat[1][i] == mat[2][i]) return mat[2][i];
    }
    if(mat[1][1] != '+' && mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2])    return mat[1][1];
    if(mat[1][1] != '+' && mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0])    return mat[1][1];

    return '?';
}


int main(){
    while(1){
        cin >> mat[0][0];
        if(mat[0][0] == '0')    break;
        cin >> mat[0][1] >> mat[0][2];
        for(int i = 1; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cin >> mat[i][j];
            }
        }
        char res = judge();
        if(res == '?')  cout << "NA" << endl;
        else            cout << res << endl;
    }
    return 0;
}