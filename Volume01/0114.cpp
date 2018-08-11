// x^t = 1 mod m のとき、
// x^(kt) = 1 mod m.
#include<iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a*b / gcd(a,b);
}

int main(){
    ll a1, m1, a2, m2, a3, m3;
    
    while(1){
        cin >> a1 >> m1 >> a2 >> m2 >> a3 >> m3;
        if(a1+m1+a2+m2+a3+m3 == 0)  break;
        
        ll x = 1, y = 1, z = 1;

        ll tmp = a1;
        while(tmp != 1){
            x++;
            tmp = (tmp*a1)%m1;
        }
        
        tmp = a2;
        while(tmp != 1){
            y++;
            tmp = (tmp*a2)%m2;
        }

        tmp = a3;
        while(tmp != 1){
            z++;
            tmp = (tmp*a3)%m3;
        }

        ll ans = lcm(lcm(x,y), z);
        cout << ans << endl;
    }

    return 0;
}