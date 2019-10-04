#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    double d[n], r[n];
    for(int i = 0; i < n; i++)  cin >> r[i];
    double ans = 0;
    for(int i = 0; i < n; i++){
        d[i] = r[i];
        for(int j = 0; j < i; j++){
            d[i] = max(d[i], d[j]+2*sqrt(r[i]*r[j]));
        }
        ans = max(ans, r[i]+d[i]);
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
