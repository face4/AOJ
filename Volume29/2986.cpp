#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)

typedef long long ll;

const ll mod = 1e9+7;
ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

bool isPalindrome(string s){
    int n = s.length();
    for(int i = 0; i < n; i++){
        if(s[i] != s[n-1-i])    return false;
    }
    return true;
}

void ng(){
    cout << 0 << endl;
    exit(0);
}

int main(){
    string zaki, o;
    int n;
    cin >> zaki >> o >> n;

    if(n <= o.length()){
        string hoge = o.substr(o.length()-n);
        reverse(hoge.begin(), hoge.end());
        string s = hoge + zaki + hoge + o;
        cout << isPalindrome(s) << endl;
        return 0;
    }

    map<int, char> ind;
    for(int i = 0; i < o.length(); i++) ind[i] = o[o.length()-1-i];

    ll len = n + zaki.length() + n + o.length();

    for(int i = 0; i < zaki.length(); i++){
        ll index = n + i;
        ll inv = len - 1 - index;
        if(inRange(inv, n, n+zaki.length()) && zaki[inv-n] != zaki[i]){
            ng();
        }else if(inRange(inv, n+zaki.length(), n+zaki.length()+n)){
            if(ind.count(inv-n-zaki.length()) == 1 && ind[inv-n-zaki.length()] != zaki[i]){
                ng();
            }
            ind[inv-n-zaki.length()] = zaki[i];
        }
    }

    ll ret = modpow(26, (n-ind.size()+1)/2);
    cout << ret << endl;
    return 0;
}