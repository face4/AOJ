#include<iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

string s;

void solve(ll mo){
    ll ch = 0;
    bool dot = false;
    for(int i = 0; i < s.length(); i++){
        if(dot) mo *= 10;
        if(s[i] == '.') dot = true;
        else            ch = 10*ch + s[i]-'0';
    }
    ll g = gcd(ch, mo);
    ch /= g, mo /= g;
    printf("%lld/%lld\n", ch, mo);
}

int main(){
    cin >> s;
    int pos;
    for(pos = 0; pos < s.length(); pos++)   if(s[pos] == '(')   break;
    if(pos < s.length()){
        string t = "", u = "";
        ll tmp = 1;
        for(int i = 0; i < s.length()-pos-2; i++)   tmp *= 10;
        for(int i = 0; i < s.length()-1; i++){
            if(s[i] != '(') t += s[i];
            if(i < pos) u += s[i];
        }
        double a = stod(t) * tmp, b = stod(u);
        double c = a-b;
        tmp--;
        s = to_string(c);
        solve(tmp);
    }else{
        solve(1);
    }
    return 0;
}