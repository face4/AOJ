#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    int rad, n;
    while(cin >> rad >> n, rad+n){
        int height[40] = {};
        for(int i = 0; i < n; i++){
            int xl, xr, h;
            cin >> xl >> xr >> h;
            for(int j = xl; j < xr; j++){
                height[20+j] = max(height[20+j], h);
            }
        }
        double l = 0.0, r = 21;
        for(int i = 0; i < 100; i++){
            double mid = (l+r)/2;
            bool safe = true;
            for(int j = -rad; j < rad; j++){
                safe &= height[20+j] >= mid-rad+sqrt(pow(rad,2.0)-pow(min(fabs(j),fabs(j+1)),2.0));
            }
            if(!safe)   r = mid;
            else        l = mid;
        }
        cout << fixed << setprecision(12) << l << endl;
    }
    return 0;
}