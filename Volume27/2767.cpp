#include<iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int cnt[26] = {};
    for(char c : s){
        cnt[c-'a']++;
    }
    int d[10] = {};
    for(int i = 0; i < 26; i++) d[cnt[i]]++;
    int ko = 0, ans = 0;
    for(int i = 1; i <= 9; i++){
        if(d[i] == 0)   continue;
        if(d[i] == 1){
            ko++, ans += 3-(i==1)*2;
        }else{
            ko++, ans += (i!=1)*4+(2*d[i]-1);
        }
    }
    ans += ko-1;
    cout << ans << endl;
    return 0;
}