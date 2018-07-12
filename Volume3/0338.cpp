#include<iostream>
using namespace std;

int gcd(int a, int b){
    return b==0 ? a : gcd(b, a%b);
}

int main(){
    int w, h, c;
    cin >> w >> h >> c;

    int g = gcd(w,h);
    cout << w*h/g/g*c << endl;
    
    return 0;
}