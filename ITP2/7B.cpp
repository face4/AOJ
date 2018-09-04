#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;
    int q, op, x;
    cin >> q;

    while(q-- > 0){
        cin >> op >> x;
        if(op == 0){
            s.insert(x);
            cout << s.size() << endl;
        }else if(op == 1){
            cout << s.count(x) << endl;
        }else if(op == 2){
            s.erase(x);
        }
    }

    return 0;
}