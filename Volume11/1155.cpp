#include<iostream>
#include<cctype>
using namespace std;

typedef string::const_iterator State;
#define inRange(x,a,b) (a <= x && x <= b)

int p, q, r;

int NOT(int a){
    return 2-a;
}
int AND(int a, int b){
    if(a == 2 & b == 2)     return 2;
    if(a >= 1 && b >= 1)    return 1;
    return 0;
}
int OR(int a, int b){
    if(a == 2 || b == 2)    return 2;
    if(a == 1 || b == 1)    return 1;
    return 0;
}

int formula(State &begin){
    if(inRange(*begin, '0', '2')){
        int ret = (*begin)-'0';
        begin++;
        return ret;
    }
    if(inRange(*begin, 'P', 'R')){
        char c = *(begin);
        begin++;
        if(c == 'P')    return p;
        if(c == 'Q')    return q;
        if(c == 'R')    return r;
    }
    if(*begin == '-'){
        begin++;
        return NOT(formula(begin));
    }
    if(*begin == '('){
        begin++;
        int ret = formula(begin);
        while(true){
            if(*begin == '*'){
                begin++;
                ret = AND(ret, formula(begin));
            }else if(*begin == '+'){
                begin++;
                ret = OR(ret, formula(begin));
            }else{
                break;
            }
        }
        begin++;    // ')'
        return ret;
    }
}

int main(){
    string s;
    while(cin >> s, s != "."){
        int ans = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    p = i, q = j, r = k;
                    State begin = s.begin();
                    if(formula(begin) == 2) ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}