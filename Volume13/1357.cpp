#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    double d[n], r[n];
    for(int i = 0; i < n; i++)  cin >> d[i];
    r[0] = d[0];
    double ans = r[0]+d[0];
    for(int i = 1; i < n; i++){
        double tmp = d[i];
        for(int j = 0; j < i; j++){
            tmp = max(tmp, r[j]+sqrt(pow(d[i]+d[j],2.0)-pow(fabs(d[i]-d[j]),2.0)));
        }
        r[i] = tmp;
        ans = max(ans, r[i]+d[i]);
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
