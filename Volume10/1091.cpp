#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double heron(double i, double j, double k){
    double s = (i+j+k)/2;
    return sqrt(s * (s-i) * (s-j) * (s-k));
}

int main(){
    int a, l, x;
    while(cin >> a >> l >> x){
        cout << fixed << setprecision(10) << heron(a,l,l) + 2*heron(l, (l+x)/2.0, (l+x)/2.0) << endl;
    }
    return 0;
}