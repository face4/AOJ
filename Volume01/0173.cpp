#include<iostream>
using namespace std;

int main(){
    string s;
    int a, b;

    for(int i = 0; i < 9; i++){
        cin >> s >> a >> b;
        cout << s << " " << a+b << " " << 200*a + 300*b << endl;
    }

    return 0;
}