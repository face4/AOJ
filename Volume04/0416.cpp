#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double a, t, r;
    cin >> a >> t >> r;
    cout << fixed << setprecision(12) << t/a*r << endl;
    return 0;
}