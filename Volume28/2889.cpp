#include<iostream>
using namespace std;
#define rep(i, n) for(int i = 1; i < (n); i++)

int main(){
    string s;
    cin >> s;
    int n = s.length(), ans = 0;
    rep(i,4)rep(j,4)rep(k,4)rep(l,4){
        if(i+j+k+l != n)    continue;
        string ss = s.substr(0,i), t = s.substr(i, j), u = s.substr(i+j, k), v = s.substr(i+j+k, l);
        if((i!=1 && ss[0]=='0') || (j!=1 && t[0]=='0') || (k!=1 && u[0]=='0') || (l!=1 && v[0]=='0'))    continue;
        if(stoi(ss) < 256 && stoi(t) < 256 && stoi(u) < 256 && stoi(v) < 256)    ans++;
    }
    cout << ans << endl;
    return 0;
}