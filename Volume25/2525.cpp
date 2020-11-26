#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll m, rd, rr, cd, cr;
    cin >> m >> rd >> rr >> cd >> cr;
    ll x = (cd*100+rd-1)/rd;
    ll y = (cr*100+rr-1)/rr;
    m -= x+y;
    if(m >= 0)  cout << m << endl;
    else        cout << -1 << endl;
    return 0;
}