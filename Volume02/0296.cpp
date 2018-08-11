#include<iostream>
using namespace std;

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if(a + 5*b + 10*c + 50*d + 100*e + 500*f >= 1000){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}
