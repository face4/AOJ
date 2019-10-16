#include<iostream>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> c >> d >> a >> b;
    if(a == -1 || b == -1){
        a = d, b = c;
    }
    if(a > b)       cout << "Alice" << endl;
    else if(a < b)  cout << "Bob" << endl;
    else            cout << "Draw" << endl;
    return 0;
}
