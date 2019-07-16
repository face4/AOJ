#include<iostream>
#include<set>
using namespace std;

set<string> used;

void out(){
    cout << "!OUT" << endl;
    exit(0);
}

string say(string s){
    cout << "?" << s << endl << flush;
    used.insert(s);
    string ret;
    cin >> ret;
    if(s[s.length()-1] != ret[0] || used.count(ret)){
        out();
    }else{
        used.insert(ret);
    }
    return ret;
}

int main(){
    string t = say("a");
    while(true){
        string k = "";  k += t[t.length()-1];
        for(char c = 'a'; c <= 'z'; c++){
            string s = k;   s += c;
            if(used.count(s) == 0){
                t = say(s);
                break;
            }
        }
    }
}