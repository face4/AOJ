#include<iostream>
#include<vector>
#include<algorithm>
#include<cfloat>
#include<cmath>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int p, n;
    while(cin >> p >> n, p+n){
        double l = 0, r = DBL_MAX, sq = sqrt(p);
        int lc, lm, rc, rm;
        for(int m = 1; m <= n; m++){
            int ll = (int)(sq*m), rr = ceil(sq*m);
            if(ll < 1)  ll = 1;
            if(rr < 1)  rr = 1;
            if(ll > n)  ll = n;
            if(rr > n)  rr = n;
            if((double)ll/m < sq && (double)ll/m > l){
                l = (double)ll/m, lc = ll, lm = m;
            }
            if((double)rr/m > sq && (double)rr/m < r){
                r = (double)rr/m, rc = rr, rm = m;
            }
        }
        int g = gcd(lc, lm);    lc /= g, lm /= g;
        g = gcd(rc, rm);        rc /= g, rm /= g;
        printf("%d/%d %d/%d\n", rc, rm, lc, lm);
    }
    return 0;
}