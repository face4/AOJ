#include<iostream>
#include<cctype>
#include<string>
using namespace std;
typedef string::const_iterator State;

int number(State &begin);
int factor(State &begin);
int term(State &begin);
int expression(State &begin);

int expression(State &begin){
    int ret = term(begin);

    while(1){
        if(*begin == '+'){
            begin++;
            ret += term(begin);
        }else if(*begin == '-'){
            begin++;
            ret -= term(begin);
        }else{
            break;
        }
    }

    return ret;
}

int term(State &begin){
    int ret = factor(begin);

    while(1){
        if(*begin == '*'){
            begin++;
            ret *= factor(begin);
        }else if(*begin == '/'){
            begin++;
            ret /= factor(begin);
        }else{
            break;
        }
    }

    return ret;
}

int factor(State &begin){
    if(*begin == '('){
        begin++;    // (
        int ret = expression(begin);
        begin++;    // )
        return ret;
    }else{
        return number(begin);
    }
}

int number(State &begin){
    int ret = 0;

    while(isdigit(*begin)){
        ret = ret*10 + (*begin - '0');
        begin++;
    }

    return ret;
}

int main(){
    int n;
    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);

        State begin = s.begin();
        int ans = expression(begin);
        cout << ans << endl;
    }

    return 0;
}