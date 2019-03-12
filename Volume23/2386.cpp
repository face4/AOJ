#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int c[n][n];
    for(int i = 0; i < n*n; i++)    cin >> c[i/n][i%n];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ans += min(c[i][j], c[j][i]);
        }
    }
    cout << ans << endl;
    return 0;
}