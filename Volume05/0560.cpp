#include<iostream>
using namespace std;

char mat[1001][1001];

int J[1001][1001] = {}, O[1001][1001] = {}, I[1001][1001] = {};

int main(){
    int h, w, k;
    cin >> h >> w >> k;

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> mat[i][j];
        }
    }

    J[1][1] = (mat[1][1] == 'J');
    O[1][1] = (mat[1][1] == 'O');
    I[1][1] = (mat[1][1] == 'I');

    for(int i = 2; i <= h; i++){
        J[i][1] += J[i-1][1];
        O[i][1] += O[i-1][1];
        I[i][1] += I[i-1][1];
        if(mat[i][1] == 'J')  J[i][1]++;
        if(mat[i][1] == 'O')  O[i][1]++;
        if(mat[i][1] == 'I')  I[i][1]++;
    }

    for(int j = 2; j <= w; j++){
        J[1][j] += J[1][j-1];
        O[1][j] += O[1][j-1];
        I[1][j] += I[1][j-1];
        if(mat[1][j] == 'J')  J[1][j]++;
        if(mat[1][j] == 'O')  O[1][j]++;
        if(mat[1][j] == 'I')  I[1][j]++;
    }

    for(int i = 2; i <= h; i++){
        for(int j = 2; j <= w; j++){
            J[i][j] = (mat[i][j] == 'J') + J[i-1][j] + J[i][j-1] - J[i-1][j-1];
            O[i][j] = (mat[i][j] == 'O') + O[i-1][j] + O[i][j-1] - O[i-1][j-1];
            I[i][j] = (mat[i][j] == 'I') + I[i-1][j] + I[i][j-1] - I[i-1][j-1];
        }
    }

    int a, b, c, d;
    for(int i = 0; i < k; i++){
        cin >> a >> b >> c >> d;
        int jungle = J[c][d]-J[a-1][d]-J[c][b-1]+J[a-1][b-1];
        int ocean = O[c][d]-O[a-1][d]-O[c][b-1]+O[a-1][b-1];
        int ice = I[c][d]-I[a-1][d]-I[c][b-1]+I[a-1][b-1];
        cout << jungle << " " << ocean << " " << ice << endl;
    }

    return 0;
}