#include<iostream>
using namespace std;

int p, q, a, n, cnt;

int gcd(int c, int d){
    return d == 0 ? c : gcd(d, c%d);
}

void dfs(int num, int now, int acc, int tmpp, int tmpq){
    if(p == tmpp && q == tmpq){
        cnt++;
        return;
    }
    
    if(num == n)    return;
    
    if(tmpp*now*q+(n-num)*tmpq*q < p*tmpq*now || acc*now > a)    return;
    
    int mo = tmpq*now;
    int ch = tmpp*now + tmpq;
    int g = gcd(mo, ch);
    mo /= g, ch /= g;

    if(ch*q <= mo*p)    dfs(num+1, now, acc*now, ch, mo);
    
    dfs(num, now+1, acc, tmpp, tmpq);
}

int main(){
    while(cin >> p >> q >> a >> n, p+q+a+n){
        int g = gcd(p, q);
        p /= g, q /= g;
        cnt = 0;
        dfs(0, 1, 1, 0, 1);
        cout << cnt << endl;
    }
    return 0;
}