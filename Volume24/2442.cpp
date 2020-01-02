// 解説を見た　なるほど
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

bool equals(double x, double y){
    return fabs(x-y) < 1e-6;
}

int main(){
    int n;
    cin >> n;
    if(n%2){
        cout << "NA" << endl;
        return 0;
    }
    double x[n], y[n];
    for(int i = 0; i < n; i++)  cin >> x[i] >> y[i];
    double px = (x[0]+x[n/2])/2.0, py = (y[0]+y[n/2])/2.0;
    bool ok = true;
    for(int i = 1; i < n/2; i++){
        ok &= equals(px-x[i], x[n/2+i]-px) && equals(py-y[i], y[n/2+i]-py);
    }
    if(ok)  cout << fixed << setprecision(12) << px << " " << py << endl;
    else    cout << "NA" << endl;
    return 0;
}