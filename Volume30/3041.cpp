#include<iostream>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    int cur = 0;
    int op, k;

    while(q-- > 0){
        cin >> op >> k;
        if(op == 0){
            cout << (cur+k-1)%n+1 << endl;
        }else{
            cur = (cur+k)%n;
        }
    }

    return 0;
}