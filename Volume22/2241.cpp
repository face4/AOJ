#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)

int rev[2][2][1000001], count[2][2][500] = {}, naname[2][2] = {};

void play(int id, int n, int x, int &cnt){
    int i = rev[id][0][x], j = rev[id][1][x];
    count[id][0][i]++;
    if(count[id][0][i] == n)    cnt++;
    count[id][1][j]++;
    if(count[id][1][j] == n)    cnt++;
    if(i == j){
        naname[id][0]++;
        if(naname[id][0] == n)  cnt++;
    }
    if(i+j == n-1){
        naname[id][1]++;
        if(naname[id][1] == n)  cnt++;
        if(n == 1)  cnt-=3; // nが1の場合、縦横斜めを4回カウントしてしまうので3を引いて帳尻を合わせる
    }
}

int main(){
    int n, u, v, m;
    cin >> n >> u >> v >> m;
    memset(rev, 0x3f, sizeof(rev));
    int x;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                cin >> x;
                rev[i][0][x] = j;
                rev[i][1][x] = k;
            }
        }
    }
    int usa = 0, cat = 0;
    while(m-- > 0){
        int x;  cin >> x;
        if(rev[0][0][x] < n)    play(0, n, x, usa);
        if(rev[1][0][x] < n)    play(1, n, x, cat);
        int judge = (usa >= u ? 2 : 0) + (cat >= v ? -3 : 0);
        if(judge == 2){
            cout << "USAGI" << endl;
            return 0;
        }else if(judge == -3){
            cout << "NEKO" << endl;
            return 0;
        }else if(judge == -1){
            break;
        }
    }
    cout << "DRAW" << endl;
    return 0;
}