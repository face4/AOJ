#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    int q, op, x, y;
    set<int> s;

    cin >> q;

    while(q-- > 0){
        cin >> op >> x;
        if(op == 0){
            s.insert(x);
            cout << s.size() << endl;
        }else if(op == 1){
            cout << (s.find(x) != s.end()) << endl;
        }else if(op == 2){
            s.erase(x);
        }else if(op == 3){
            cin >> y;
            auto l = s.lower_bound(x);
            auto r = s.upper_bound(y);
            for(; l != r; l++)  printf("%d\n", *l);
        }
    }

    return 0;
}