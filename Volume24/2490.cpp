#include<iostream>
using namespace std;

int main(){
    int n, x, acc = 0;
    cin >> n;
    char c;
    for(int i = 0; i < n; i++){
        cin >> c >> x;
        acc += (c=='(' ? 1 : -1)*x;
        if(acc < 0) break;
    }
    cout << (acc==0 ? "YES" : "NO") << endl;
    return 0;
}