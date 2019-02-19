#include<iostream>
using namespace std;

int cnt[500][500] = {};
char mat[1000][1000];

int main(){
    int c, n;
    cin >> c >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
            int p = mat[i][j]-'0';
            if(p){
                cnt[(i >= n/2 ? n-1-i : i)][(j >= n/2 ? n-1-j : j)] += 1;
            }
        }
    }

    auto f = [&]()-> int{
        int ret = 0;
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n/2; j++){
                if(cnt[i][j]%4) ret++;
            }
        }
        return ret;
    };

    int ans = 0;
    int problem = f();
    if(problem == 0)    ans++;

    for(int i = 0; i < c-1; i++){
        int d;
        cin >> d;
        while(d-- > 0){
            int r, c;
            cin >> r >> c;
            r--, c--;
            mat[r][c] = (mat[r][c] == '0' ? '1' : '0');
            if(cnt[(r >= n/2 ? n-1-r : r)][(c >= n/2 ? n-1-c : c)]%4==0)    problem++;
            cnt[(r >= n/2 ? n-1-r : r)][(c >= n/2 ? n-1-c : c)] += 2*(mat[r][c]=='1')-1;
            if(cnt[(r >= n/2 ? n-1-r : r)][(c >= n/2 ? n-1-c : c)]%4==0)    problem--;
        }
        if(problem == 0) ans++;
    }

    cout << ans << endl;

    return 0;
}