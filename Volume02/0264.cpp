#include<iostream>
using namespace std;

typedef string::const_iterator State;
#define inRange(x,a,b) (a <= x && x <= b)

int expression(State &begin);
int term(State &begin);
int factor(State &begin);
int number(State &begin);

int mod;
bool ng = false;

int modpow(int a, int b){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        int d = modpow(a, b/2);
        return (d*d) % mod;
    }else{
        return (a%mod * modpow(a, b-1)) % mod;
    }
}

int expression(State &begin){
    int ret = term(begin);
    while(true){
        if(*begin == '+'){
            begin++;
            ret = (ret+term(begin))%mod;
        }else if(*begin == '-'){
            begin++;
            ret = (ret-term(begin)+mod)%mod;
        }else{
            break;
        }
    }
    return ret;
}

int term(State &begin){
    int ret = factor(begin);
    while(true){
        if(*begin == '*'){
            begin++;
            ret = (ret * factor(begin))%mod;
        }else if(*begin == '/'){
            begin++;
            int divide = factor(begin);
            if(divide == 0)  ng = true, divide = 1;
            int inv = modpow(divide, mod-2);
            ret = (ret * inv)%mod;
        }else{
            break;
        }
    }
    return ret;
}

int factor(State &begin){
    if(*begin == '('){
        begin++;
        int ret = expression(begin);
        begin++;    // ')'
        return ret;
    }
    return number(begin);
}

int number(State &begin){
    int ret = 0;
    while(inRange(*begin, '0', '9')){
        ret *= 10;
        ret += *begin-'0';
        begin++;
    }
    return ret;
}

int main(){
    string s;
    while(getline(cin, s), s != "0:"){
        ng = false;
        string t = "";
        int cur = 0;
        while(s[cur] != ':')    cur++;
        mod = stoi(s.substr(0, cur));
        cur++;
        while(cur < s.length()){
            if(s[cur] != ' ')   t += s[cur];
            cur++;
        } 
        State begin = t.begin();
        int ans = expression(begin);
        if(ng){
            cout << "NG" << endl;
        }else{
            cout << t << " = " << ans << " (mod " << mod << ")" << endl;
        }
    }
    return 0;
}