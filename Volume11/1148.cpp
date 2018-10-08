#include<iostream>
#include<cstring>
using namespace std;

bool use[10000][1260];
int pc[1000];

int main(){
    int n, m, r, q;
    while(cin >> n >> m, n+m){
        memset(use, 0, sizeof(use));
        memset(pc, 0, sizeof(pc));

        cin >> r;
        int a, b, c, d;
        for(int i = 0; i < r; i++){
            cin >> a >> b >> c >> d;
            b--, c--;
            if(d == 1){
                pc[b] = a;
            }else if(d == 0){
                for(int i = pc[b]; i < a; i++){
                    use[c][i] = true;
                }
                pc[b] = 0;
            }
        }

        cin >> q;
        int ts, te, x;
        for(int i = 0; i < q; i++){
            cin >> ts >> te >> x;
            x--;
            int cnt = 0;
            for(int j = ts; j < te; j++)    if(use[x][j])   cnt++;
            cout << cnt << endl;
        }
    }

    return 0;
}