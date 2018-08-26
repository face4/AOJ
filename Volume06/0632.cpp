#include<iostream>
using namespace std;

int l[101][101] = {}, u[101][101] = {};

int main(){
    int n, m, d, ans = 0;
    char x;

    cin >> n >> m >> d;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> x;
            if(x == '.'){
                u[i][j] = u[i-1][j]+1;
                l[i][j] = l[i][j-1]+1;
                ans += (l[i][j] >= d) + (u[i][j] >= d);
            }
        }
    }

    cout << ans << endl;

    return 0;
}