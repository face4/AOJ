#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double a, b;
    cin >> a >> b;
    if(a > b)   swap(a, b);
    if(b-a < 180){
        a += (b-a)/2;
        if(a > 360) a -= 360.0;
    }else{
        a -= (360-b+a)/2;
        if(a < 0)   a += 360.0;
    }
    cout << fixed << setprecision(10) << a << endl;
    return 0;
}