// 嫌い
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    double d;
    cin >> d;
    cout << fixed << setprecision(12) << max((double)((int)d+1), sqrt(2)*d) << endl;
    return 0;
}