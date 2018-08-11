#include<iostream>
using namespace std;

int main(){
    for(int i = 0; i < 3; i++){
        int h, m, s, a, b;
        cin >> h >> m >> s;
        a = 3600*h+60*m+s;
        cin >> h >> m >> s;
        b = 3600*h+60*m+s;
        int stay = b-a;
        cout << stay/3600 << " "
            << stay%3600/60 << " " 
            << stay%60 << endl;
    }
    return 0;
}
