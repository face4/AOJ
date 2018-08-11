#include<iostream>
using namespace std;

int main(){
    int x, a = 2001, b = 2001;
    for(int i = 0; i < 3; i++){
        cin >> x;
        a = min(a,x);
    }
    for(int i = 0; i < 2; i++){
        cin >> x;
        b = min(b,x);
    }
    cout << a+b-50 << endl;
    return 0;
}
