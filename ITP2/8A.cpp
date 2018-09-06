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
            cout << m[s] << endl;
        }
    }

    return 0;
}