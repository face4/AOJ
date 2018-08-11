#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    double n, t;
    cin >> n >> t;

    double maxangle = -1;
    for(int i = 0; i < n; i++){
        double x, h;
        cin >> x >> h;
        maxangle = max(maxangle, atan2(h,x));
    }

    cout << fixed << setprecision(6) << t*tan(maxangle) << endl;
    return 0;
}