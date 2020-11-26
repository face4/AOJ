#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int l, n;
    string s;
    cin >> l >> n >> s;
    ll suc = 0;
    for(int i = 1; i < l; i++)  suc += (s[i-1]==s[i]&&s[i]=='o');
    ll ret = l;
    while(n--){
        ret += 3*suc;
        suc *= 2;
    }
    cout << ret << endl;
    return 0;
}