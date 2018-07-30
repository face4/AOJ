#include<iostream>
using namespace std;

int main(){
    int a, b, c, d, p;
    cin >> a >> b >> c >> d >> p;
    cout << min(a*p, b + max(0, p-c)*d) << endl;
    return 0;
}