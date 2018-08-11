#include<iostream>
using namespace std;

int main(){
    int b, r, g, c, s, t;
    while(1){
        cin >> b >> r >> g >> c >> s >> t;
        if(b+r+g+c+s+t == 0)    break;
    
        int medal = 100;
        medal += 80*b;
        medal += 54*r;
        medal += 7*g;
        medal += 2*c;
        medal -= (t-s-5*b-3*r)*3;
        cout << medal << endl;
    }
    return 0;
}
