#include<iostream>
#include<vector>
using namespace std;

bool vis[101] = {};
int ans;
vector<int> v[101];

void dfs(int x, int l){
    vis[x] = true;
    ans = max(ans, l);
    for(int j : v[x]){
        if(!vis[j]) dfs(j, l+1);
    }
    vis[x] = false;
}

int main(){
    int n;
    while(cin >> n, n){
        for(int i = 1; i <= 100; i++)   v[i].clear();
        for(int i = 1; i <= n; i++){
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        ans = 0;
        for(int i = 1; i <= 100; i++){
            dfs(i, 1);
        }
        cout << ans << endl;
    }
    return 0;
}