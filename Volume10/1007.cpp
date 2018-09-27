#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n, caseNum = 1;
    while(cin >> n, n){
        int mat[n][n];
        int i = 0, j = 0;
        int num = 1;

        for(int wave = 0; wave <= n+n-2; wave++){
            if(wave % 2 == 1){
                for(i = max(0, wave-n+1); i < min(wave+1,n); i++)   mat[i][wave-i] = num++;
            }else{
                for(j = max(0, wave-n+1); j < min(wave+1,n); j++)   mat[wave-j][j] = num++;
            }
        }

        cout << "Case " << caseNum++ << ":" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << right << setw(3) << mat[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}