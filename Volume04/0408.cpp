#include<iostream>
#include<stack>
using namespace std;

int main(){
    int l;
    cin >> l;
    stack<int> s;
    bool b[101] = {};
    for(int i = 1; i <= l; i++){
        int x;  cin >> x;
        bool ok = true;
        if(x > 0){
            if(b[x])    ok = false;
            b[x] = true;
            s.push(x);
        }else{
            x = -x;
            if(s.empty() || s.top() != x)  ok = false;
            if(!s.empty())  s.pop();
            b[x] = false;
        }
        if(!ok){
            cout << i << endl;
            return 0;
        }
    }
    cout << "OK" << endl;
    return 0;
}