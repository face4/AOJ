#include<iostream>
#include<iomanip>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

double p, e, t;

double dfs(int k, double l, double r){
    double m = (l+r)/2;
    if(k == 0){
        return inRange(m,t-e,t+e) ? 1.0 : 0.0;
    }
    if(r < t-e || l > t+e) return 0.0;
    if(t-e <= l && r <= t+e)    return 1.0;
    if(m >= t)    return (1-p)*dfs(k-1, l, m) + p*dfs(k-1, m, r);
    else          return p*dfs(k-1, l, m) + (1-p)*dfs(k-1, m, r);
}

int main(){
    int k;
    double l, r;
    cin >> k >> l >> r >> p >> e >> t;
    cout << fixed << setprecision(12) << dfs(k, l, r) << endl;
    return 0;
}