// 時間計算量の見積もりが出来ません
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int v[9][9], win[9], lose[9];
int ans, n;

void dfs(int i, int j){
    while(i == j || v[i][j] != 0){
        j++;
        if(j == n)  i++, j = 0;
        if(i == n){
            ans++;
            return;
        }
    }
    if(win[i]+1 <= n/2 && lose[j]+1 <= n/2){
        v[i][j] = 1; v[j][i] = -1;
        win[i]++;   lose[j]++;
        dfs(i, j);
        win[i]--;   lose[j]--;
        v[i][j] = v[j][i] = 0;
    }
    swap(i, j);
    if(win[i]+1 <= n/2 && lose[j]+1 <= n/2){
        v[i][j] = 1; v[j][i] = -1;
        win[i]++;   lose[j]++;
        dfs(j, i);
        win[i]--;   lose[j]--;
        v[i][j] = v[j][i] = 0;
    }
}

int main(){
    while(cin >> n, n){
        memset(v, 0, sizeof(v));
        memset(win, 0, sizeof(win));
        memset(lose, 0, sizeof(lose));
        int m;
        cin >> m;
        bool ini = true;
        while(m-- > 0){
            int x, y;
            cin >> x >> y;
            x--, y--;
            v[x][y] = 1; v[y][x] = -1;
            win[x]++, lose[y]++;
            ini &= win[x] <= n/2 && lose[y] <= n/2;
        }
        if(!ini){
            cout << 0 << endl;
            continue;
        }
        ans = 0;
        dfs(0, 0);
        cout << ans << endl;
    }
    return 0;
}