#include<iostream>
using namespace std;

int main(){
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    if(a < 0) cout << -a*c+d+b*e << endl;
    else      cout << (b-a)*e << endl;
    return 0;
}