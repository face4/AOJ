#include<iostream>
using namespace std;

int n, k, s;
int ans;

void dfs(int i, int k, int s){
    if(k == 0){
        if(s == 0)  ans++;
        return;
    }

    if(i > n || i > s)   return;

    dfs(i+1, k-1, s-i);
    dfs(i+1, k, s);
}

int main(){
    while(cin >> n >> k >> s, n+k+s){
        ans = 0;
        dfs(1, k, s);
        cout << ans << endl;
    }
    return 0;
}