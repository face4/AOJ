#include<iostream>
using namespace std;

int main(){
    int h, r;
    cin >> h >> r;

    if(h > -r)          cout << 1 << endl;
    else if(h == -r)    cout << 0 << endl;
    else if(h < -r)     cout << -1 << endl;

    return 0;
}