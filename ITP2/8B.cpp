#include<iostream>
#include<map>
using namespace std;

int main(){
    map<string, int> m;
    int q, op, x;
    string s;
    
    cin >> q;
    while(q-- > 0){
        cin >> op;
        if(op == 0){
            cin >> s >> x;
            m[s] = x;
        }
        if(op == 1){
            cin >> s;
            if(m.count(s))  cout << m[s] << endl;
            else            cout << 0 << endl;
        }
        if(op == 2){
            cin >> s;
            m.erase(s);
        }
    }

    return 0;
}