#include<iostream>
using namespace std;

#define inRange(x,a,b) (a <= x && x <= b)
typedef string::const_iterator State;

int bit;

bool NOT(bool x){
    return !x;
}
bool AND(bool x, bool y){
    return x&&y;
}
bool OR(bool x, bool y){
    return x||y;
}
bool IMP(bool x, bool y){
    return !x || y;
}

bool formula(State &begin){
    if(inRange(*begin, 'a', 'k') || inRange(*begin, 'F', 'T')){
        char c = *begin;
        begin++;
        if(c == 'T')    return true;
        else if(c == 'F')    return false;
        return (bit>>(c-'a'))&1;
    }
    if(*begin == '-'){
        begin++;
        return NOT(formula(begin));
    }
    if(*begin == '('){
        begin++;
        bool ret = formula(begin);
        char c = *begin;
        begin++;
        if(c == '*')        ret = AND(ret, formula(begin));
        else if(c == '+')   ret = OR(ret, formula(begin));
        else if(c == '-')   begin++, ret = IMP(ret, formula(begin));
        begin++; // ')'
        return ret;
    }
}

int main(){
    string s;
    while(cin >> s, s != "#"){
        int eq = 0;
        while(s[eq] != '=') eq++;
        string a = s.substr(0, eq), b = s.substr(eq+1);
        bool valid = true;
        for(bit = 0; bit < 1<<11; bit++){
            State ait = a.begin(), bit = b.begin();
            valid &= formula(ait)==formula(bit);
        }
        cout << (valid ? "YES" : "NO") << endl;
    }
    return 0;
}