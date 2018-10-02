#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        bool sink = true, l = true, r = true;
        int ans = 0;
        string op;
        for(int i = 0; i < n; i++){
            cin >> op;
            if(op == "lu")  l = false;
            if(op == "ru")  r = false;
            if(op == "ld")  l = true;
            if(op == "rd")  r = true;
            if(l == r && l != sink){
                ans++;
                sink = !sink;
            }
        }
        cout << ans << endl;
    }
    return 0;
}