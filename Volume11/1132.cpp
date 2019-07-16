#include<iostream>
#include<cmath>
using namespace std;
const double EPS = 1e-7;

int main(){
    int n;
    while(cin >> n, n){
        double x[n], y[n];
        for(int i = 0; i < n; i++)  cin >> x[i] >> y[i];
        auto f = [&](double dx, double dy)->int{
            int ret = 0;
            for(int i = 0; i < n; i++){
                if(sqrt(pow(dx-x[i],2.0)+pow(dy-y[i],2.0)) <= 1.0+EPS)  ret++;
            }
            return ret;
        };
        int ans = 1;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                double d = sqrt(pow(x[j]-x[i],2.0)+pow(y[j]-y[i],2.0));
                if(d > 2.0) continue;
                double midx = (x[i]+x[j])/2, midy = (y[i]+y[j])/2;
                double suby = -(x[j]-x[i]), subx = y[j]-y[i];
                double norm = sqrt(suby*suby+subx*subx);
                suby /= norm, subx /= norm;
                double t = sqrt(1 - pow(midx-x[i],2.0) - pow(midy-y[i],2.0));
                ans = max(ans, f(midx+subx*t, midy+suby*t));
                ans = max(ans, f(midx-subx*t, midy-suby*t));
            }
        }
        cout << ans << endl;
    }
    return 0;
}