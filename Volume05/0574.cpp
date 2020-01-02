#include<iostream>
using namespace std;

int ma[5000][5000] = {};

int main(){
    int n, m;
    cin >> n >> m;
    while(m-- > 0){
        int a, b, x;
        cin >> a >> b >> x;
        a--, b--;
        ma[a+x][b] = max(ma[a+x][b], x+1);
    }
    int ans = 0;
    for(int i = n-1;; i--){
        int val = 0;
        for(int j = 0; j <= i; j++){
            val = max(val, ma[i][j]);
            if(val > 0) ans++;
            val--;
        }
        if(i == 0)  break;
        for(int j = 0; j <= i-1; j++){
            ma[i-1][j] = max(ma[i-1][j], ma[i][j]-1);
        }
    }
    cout << ans << endl;
    return 0;
}