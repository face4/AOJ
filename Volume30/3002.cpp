#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    ll a[6] = {};
    string t = "";
    bool plus = true;
    for(char c : s){
        if(c == '+' || c == '-'){
            if(t.back() == 'x'){
                a[1] = (plus ? 1 : -1) * (t.length() < 2 ? 1 : stoi(t.substr(0,t.length()-1)));
            }else if(t.length() > 1 && t[t.length()-2] == '^'){
                a[t.back()-'0'] = (plus ? 1 : -1) * (t.length() < 4 ? 1 : stoi(t.substr(0, t.length()-3)));
            }
            t = "";
            plus = c=='+';
        }else{
            t += c;
        }
    }
    if(t.back() == 'x'){
        a[1] = (plus ? 1 : -1) * stoi(t.substr(0,t.length()-1));
    }else if(t.length() > 1 && t[t.length()-2] == '^'){
        a[t.back()-'0'] = (plus ? 1 : -1) * stoi(t.substr(0, t.length()-3));
    }else{
        a[0] = (plus ? 1 : -1) * stoi(t);
    }
    auto f = [=](ll x)->ll{
        ll ret = 0;
        for(int i = 0; i <= 5; i++){
            ll tmp = a[i];
            for(int j = 0; j < i; j++)  tmp *= x;
            ret += tmp;
        }
        return ret;
    };
    vector<int> v;
    for(ll i = 2000; i >= -2000; i--){
        if(f(i) == 0)   v.push_back(-i);
    }
    for(int i = 0; i < v.size(); i++){
        cout << "(x" << (v[i]>0 ? '+' : '-') << abs(v[i]) << ")";
    }
    cout << endl;
    return 0;
}