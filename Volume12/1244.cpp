#include<iostream>
#include<map>
#include<cctype>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

map<string, int> table;
string s;
bool ng;

int num(int &pos){
    int ret = 0;
    while(pos < s.length() && isdigit(s[pos]))  ret = ret*10 + s[pos++]-'0';
    return ret;
}

int f(int &pos){
    if(s[pos] == '('){
        pos++;  // (
        int acc = 0;
        while(pos < s.length() && s[pos] != ')'){
            acc += f(pos);
        }
        pos++;  // )
        acc *= num(pos);
        return acc;
    }else{
        string mol = "";
        mol += s[pos++];
        if(pos < s.length() && inRange(s[pos], 'a', 'z'))   mol += s[pos++];
        if(table.count(mol) == 0)   ng = true;
        int acc = table[mol];
        if(pos < s.length() && isdigit(s[pos])) acc *= num(pos);
        return acc;
    }
}

int main(){
    while(cin >> s, s != "END_OF_FIRST_PART"){
        int x;  cin >> x;
        table[s] = x;
    }
    while(cin >> s, s != "0"){
        s = "(" + s + ")1";
        ng = false;
        int pos = 0;
        int ans = f(pos);
        if(ng)  cout << "UNKNOWN" << endl;
        else    cout << ans << endl;
    }
    return 0;
}