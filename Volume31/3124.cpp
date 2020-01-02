#include<iostream>
using namespace std;

int main(){
    double a, b, p, q, r;
    cin >> a >> b >> p >> q >> r;
    double d = b*p - (b-a)*q;
    cout << b+d/(r+q) << endl;
    return 0;
}
