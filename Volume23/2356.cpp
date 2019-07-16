#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;

    int cnt[26] = {};
    for(char c : s) cnt[c-'a']++;

    int odd = 0;
    for(int i = 0; i < 26; i++) if(cnt[i]%2)    odd++, cnt[i]--;

    int n = s.length();
    if(odd > 1 || (odd == 1 && n%2 == 0) || (odd == 0 && n%2 == 1)){
        cout << 0 << endl;
    }else{
        ll ans = 1;
        for(ll i = 1; i <= n/2; i++)    ans *= i;
        for(int i = 0; i < 26; i++){
            for(int j = 1; j <= cnt[i]/2; j++){
                ans /= j;
            }
        }
        cout << ans << endl;
    }

    return 0;
}