#include<iostream>
#include<vector>
using namespace std;

vector<bool> vis(201, 0);
int n;
vector<int> v[201];

void dfs(int x){
    vis[x] = true;
    for(int j : v[x]){
        if(vis[j]){
            cout << 1 << endl;
            exit(0);
        }
        dfs(j);
    }
    vis[x] = false;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        string s;
        cin >> a >> s >> b;
        if(s == "lock") v[100+b].push_back(a);
        else            v[a].push_back(100+b);
    }
    for(int i = 1; i <= 200; i++){
        dfs(i);
    }
    cout << 0 << endl;
    return 0;
}