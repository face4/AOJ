#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;

typedef long long ll;

ll hex2dec(string s){
    ll ret = 0;
    for(char c : s) ret = ret*16 + (isdigit(c) ? c-'0' : c-'a'+10);
    return ret;
}

string dec2hex(ll val){
    string ret = "";
    while(val)  ret += (val%16 >= 10 ? val%16-10+'a' : val%16+'0'), val /= 16;
    reverse(ret.begin(), ret.end());
    if(ret == "")   ret = "0";
    return ret;
}

int main(){
    int q;
    cin >> q;
    while(q-- > 0){
        ll u[9];
        for(int i = 0; i < 9; i++){
            string s;   cin >> s;
            u[i] = hex2dec(s);
        }
        ll key = 0, ma = 1ll<<32;
        for(int i = 0; i < 32; i++){
            key += (1ll<<i);
            ll sum = 0;
            for(int j = 0; j < 8; j++)  sum += u[j]^key;
            sum %= ma;
            if(sum%(1ll<<(i+1)) != (u[8]^key)%(1ll<<(i+1)))    key -= (1ll<<i);
        }
        cout << dec2hex(key) << endl;
    }
    return 0;
}
