#include<iostream>
using namespace std;

string a, b;
int k, n;

int ans = 0;

void dfs(string val, int pos, int cnt, int bor){
    if(pos == n){
        ans = max(ans, stoi(val));
        return;
    }

    if(cnt == k || a[n-1-pos]-bor >= b[n-1-pos]){
        string tmp{(char)('0'+a[n-1-pos]-bor-b[n-1-pos])};
        dfs(tmp+val, pos+1, cnt, 0);
    }else{
        string tmp{(char)('0'+a[n-1-pos]-bor+10-b[n-1-pos])};
        dfs(tmp+val, pos+1, cnt, 1);
        dfs(tmp+val, pos+1, cnt+1, 0);
    }
}


int main(){
    cin >> a >> b >> k;
    n = a.size();
    while(b.length() != n)  b = "0" + b;
    dfs("", 0, 0, 0);
    cout << ans << endl;
    return 0;
}