#include<iostream>
using namespace std;

int extgcd(int a, int b, int &x, int &y){
    int g = a;
    x = 1, y = 0;
    if(b != 0){
        g = extgcd(b, a%b, y, x);
        y -= (a / b) * x;
    }
    return g;
}

int main(){
    int a, b, x, y, g;
    cin >> a >> b;
    g = extgcd(a, b, x, y);
    cout << x << " " << y << endl;
    return 0;
}


