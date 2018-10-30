#include<iostream>
#include<cctype>
using namespace std;

typedef string::const_iterator State;
class ParseError{};

int expr(State &begin);
int term(State &begin);
int number(State &begin);

int expr(State &begin){
    int ret = term(begin);

    while(*begin == '+'){
        begin++;
        ret += term(begin);
    }

    return ret;
}

int term(State &begin){
    int ret = number(begin);

    while(*begin == '*'){
        begin++;
        ret *= number(begin);
    }

    return ret;
}

int number(State &begin){
    int ret = *begin - '0';
    begin++;
    return ret;
}

int main(){
    string s;
    int n;

    cin >> s >> n;
    
    State it = s.begin();
    int evala = expr(it);

    int evalb = s[0]-'0';
    for(int i = 1; i < s.length(); i+=2){
        int bin = s[i+1]-'0';
        if(s[i] == '+') evalb += bin;
        if(s[i] == '*') evalb *= bin;
    }

    bool x = (evala == n);
    bool y = (evalb == n);

    if(x&&y)    cout << "U" << endl;
    else if(x)  cout << "M" << endl;
    else if(y)  cout << "L" << endl;
    else        cout << "I" << endl;

    return 0;
}