#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
    map<string, vector<int>> m;
    int q, op, x;
    string s;
    
    cin >> q;
    while(q-- > 0){
        cin >> op;
        if(op == 0){
            cin >> s >> x;
            m[s].push_back(x);
        }else if(op == 1){
            cin >> s;
            if(m.count(s)){
                for(int x : m[s])   cout << x << "\n";
            }
        }else if(op == 2){
            cin >> s;
            m[s].clear();
        }else if(op == 3){
            string l, r;
            cin >> l >> r;
            auto x = m.lower_bound(l);
            auto y = m.upper_bound(r);
            for(;x != y; x++){
                string key = (*x).first;
                for(int z : m[key])   cout << key << " " << z << "\n";
            }
        }
    }

    return 0;
}