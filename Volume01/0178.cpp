#include<iostream>
#include<cstring>
using namespace std;

int di[2] = {0, 1};
int dj[2] = {1, 0};
int mat[5010][5];

int main(){
    int n;
    while(cin >> n, n){
        memset(mat, 0, sizeof(mat));
        int ma = 1;
        for(int i = 0; i < n; i++){
            int d, p, q;
            cin >> d >> p >> q;
            d--, q--;
            int put;
            for(put = 5000; put >= 0; put--){
                bool ok = true;
                for(int j = 0; j < p; j++){
                    ok &= mat[put+j*di[d]][q+j*dj[d]] == 0;
                }
                if(!ok) break;
            }
            int h = put+1;
            for(int j = 0; j < p; j++){
                mat[h+j*di[d]][q+j*dj[d]] = 1;
            }
            int acc = 0;
            for(int hh = h; hh < 5000; hh++){
                int sum = 0;
                for(int j = 0; j < 5; j++)  sum += mat[hh][j];
                if(sum == 5){
                    for(int j = 0; j < 5; j++)  mat[hh][j] = 0;
                    acc++;
                }else{
                    for(int j = 0; j < 5; j++)  mat[hh-acc][j] = mat[hh][j];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 5000; i++){
            for(int j = 0; j < 5; j++){
                ans += mat[i][j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}