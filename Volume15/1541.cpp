#include<iostream>
using namespace std;

int n, m, c[10];
string ans = "";

void dfs(int num, int use, int res){
    if(use == 0){
        cout << ans << endl;
        exit(0);
    }
    if(num == 10)   return;
    for(int i = min(use, res/c[num]); i >= 0; i--){
        for(int j = 0; j < i; j++)  ans += (char)('0'+num);
        dfs(num+1, use-i, res-c[num]*i);
        ans = ans.substr(0, ans.size()-i);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < 10; i++) cin >> c[i];
    dfs(0, n, m);
    cout << "NA" << endl;
    return 0;
}