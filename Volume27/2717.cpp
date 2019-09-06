#include<iostream>
using namespace std;

int a[10000][100];

int main(){
    int n, m;
    cin >> n >> m;
    int tmp = 0, pos = -1;
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            char c; cin >> c;
            a[i][j] = (c == 'W');
            tmp += a[i][j];
        }
    }
    int ans = tmp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tmp += a[i][j]==0 ? 1 : -1;
        }
        if(tmp < ans){
            ans = tmp, pos = i;
        }
    }
    cout << pos+1 << " " << pos+2 << endl;
    return 0;
}