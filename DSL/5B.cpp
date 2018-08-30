#include<iostream>
using namespace std;

int sum[1001][1001] = {};

int main(){
    int n, a, b, c, d;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a >> b >> c >> d;
        sum[a][b]++;
        sum[c][d]++;
        sum[a][d]--;
        sum[c][b]--;
    }

    for(int i = 1; i < 1001; i++){
        for(int j = 0; j < 1001; j++){
            sum[i][j] += sum[i-1][j];
        }
    }

    for(int i = 0; i < 1001; i++){
        for(int j = 1; j < 1001; j++){
            sum[i][j] += sum[i][j-1];
        }
    }

    int ans = 1;
    for(int i = 0; i < 1001; i++){
        for(int j = 0; j < 1001; j++){
            ans = max(ans, sum[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}