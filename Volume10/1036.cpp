#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s, t, u;
    while(cin >> s, s != "-"){
        cin >> t >> u;
        string res = "";
        int sp = 0, tp = 0, up = 0;
        bool iss = s[0] == u[0];
        for(; up < u.length(); up++){
            if(s[sp] == u[up]){
                sp++;
            }else{
                while(t[tp] != u[up]){
                    if(iss){
                        res += s[sp++];
                        iss = false;
                    }else{
                        res += t[tp++];
                    }
                }
                if(iss){
                    res += s[sp++];
                    iss = false; // convention
                }
                tp++;
                iss = true;
            }
        }
        s = s.substr(sp), t = t.substr(tp);
        if(iss){
            res += s;
            res += t;
        }else{
            res += t;
            res += s;
        }
        cout << res << endl;
    }
    return 0;
}