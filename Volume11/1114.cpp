#include<iostream>
using namespace std;

int main(){
    int m;
    cin >> m;
    while(m-- > 0){
        int mat[5][5];
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                cin >> mat[i][j];
            }
        }
        int ans = 0;
        for(int i = 1; i <= 5; i++){
            for(int j = 1; j <= 5; j++){
                for(int k = 0; k <= 5-i; k++){
                    for(int l = 0; l <= 5-j;l++){
                        int tmp = 0;
                        for(int x = 0; x < i; x++){
                            for(int y = 0; y < j; y++){
                                tmp += mat[k+x][l+y];
                            }
                        }
                        if(tmp == i*j)  ans = max(ans, i*j);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}