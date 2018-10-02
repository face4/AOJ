#include<iostream>
using namespace std;

int main(){
    int n, m, a;
    while(cin >> n >> m >> a, n+m+a){
        int h, p, q;
        int amida[1001][101] = {};
        for(int i = 0; i < m; i++){
            cin >> h >> p >> q;
            amida[h][p] = q;
            amida[h][q] = p;
        }
        for(int i = 1000; i >= 1; i--){
            if(amida[i][a] != 0)    a = amida[i][a];
        }
        cout << a << endl;
    }
    return 0;
}