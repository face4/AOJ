#include<iostream>
using namespace std;

void dec(string s){
    int a = 0, b = 0;
    for(int i = 1; i < s.length(); i++){
        if(s[i] == 'A')     a++;
        if(s[i] == 'B')     b++;
    }

    if(a > b)   a++;
    else        b++;
    
    cout << a << " " << b << endl;
}

int main(){
    while(1){
        string s;
        cin >> s;

        if(s == "0")    break;

        dec(s);
        for(int i = 0; i < 2; i++){
            cin >> s;
            dec(s);
        }
    }
    return 0;
}