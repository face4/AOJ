#include<iostream>
using namespace std;

#define inRange(x,a,b) (a <= x && x <= b)

int main(){
    string s;
    cin >> s;

    bool num = false, low = false, upp = false, len = s.length() >= 6;
    for(char c : s){
        num |= inRange(c, '0', '9');
        low |= inRange(c, 'a', 'z');
        upp |= inRange(c, 'A', 'Z');
    }

    if(num && low && upp && len)    cout << "VALID" << endl;
    else                            cout << "INVALID" << endl;

    return 0;
}