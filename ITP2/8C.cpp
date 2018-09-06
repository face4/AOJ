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
        }else if(op == 1){
            cin >> s;
            if(m.count(s))  cout << m[s] << endl;
            else            cout << 0 << endl;
        }else if(op == 2){
            cin >> s;
            m.erase(s);
        }else if(op == 3){
            string l, r;
            cin >> l >> r;
            auto x = m.lower_bound(l);
            auto y = m.upper_bound(r);
            for(;x != y; x++)   cout << (*x).first << " " << (*x).second << "\n";
        }
    }

    return 0;
}