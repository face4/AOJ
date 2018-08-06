// https://qiita.com/port-development/items/eea3a0a225be47db0fd4
#include<iostream>
#include<cmath>
using namespace std;

#define PI 2*acos(0.0)
#define DEGtoRAD(X) (X*PI)/180.0

int main(){
    double a, b, c, d;
    while(cin >> a >> b >> c >> d){
        if(a+b+c+d == -4)   break;
        a = DEGtoRAD(a);
        b = DEGtoRAD(b);
        c = DEGtoRAD(c);
        d = DEGtoRAD(d);
        double x = acos(sin(a)*sin(c) + cos(a)*cos(c)*cos(b-d));
        int ans = round(6378.1 * x);
        cout << ans << endl;
    }
    return 0;
}
