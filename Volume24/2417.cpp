#include<iostream>
#include<map>
using namespace std;

int main(){
    map<char, char> ma, mb;
    ma['2'] = 'k';
    ma['3'] = 's';
    ma['4'] = 't';
    ma['5'] = 'n';
    ma['6'] = 'h';
    ma['7'] = 'm';
    ma['8'] = 'y';
    ma['9'] = 'r';
    mb['T'] = 'a';
    mb['L'] = 'i';
    mb['U'] = 'u';
    mb['R'] = 'e';
    mb['D'] = 'o';
    char a, b;
    while(cin >> a >> b){
        if(a == '0'){
            if(b == 'T')    cout << "wa";
            if(b == 'U')    cout << "nn";
            if(b == 'D')    cout << "wo";
        }else{
            if(a != '1')    cout << ma[a];
            cout << mb[b];
        }
    }
    cout << endl;
    return 0;
}
