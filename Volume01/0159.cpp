#include<iostream>
#include<cfloat>
#include<cmath>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){ 
        int ans = -1;
        double mi = DBL_MAX;

        int p;
        double h, w;
        for(int i = 0; i < n; i++){
            cin >> p >> h >> w;
            h /= 100;
            double diff = fabs(22.0 - w/h/h);
            if(diff < mi){
                mi = diff;
                ans = p;
            }
        }

        cout << ans << endl;
    }
    return 0;
}