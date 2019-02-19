#include<iostream>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        string s[n];
        int t[n];
        for(int i = 0; i < n; i++)  cin >> s[i] >> t[i];
        int ans = 0;
        while(m-- > 0){
            string k;   cin >> k;
            for(int i = 0; i < n; i++){
                int cnt = 0;
                for(int j = 0; j < 8; j++)  if(s[i][j]=='*' || s[i][j]==k[j])   cnt++;
                if(cnt == 8)    ans += t[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}