#include<iostream>
using namespace std;

int ans;
void dfs(int res, int now){
    if(now == 1){
        ans++;
        return;
    }
    for(int j = res/(now*now); j >= 0; j--){
        dfs(res-j*now*now, now-1);
    }
}

int main(){
    int n;
    while(cin >> n, n)  ans = 0, dfs(n, 17), cout << ans << endl;
    return 0;
}