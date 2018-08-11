#include<iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}

int main(){
    int n;
    while(cin >> n, n){
        ll d[n], v[n], mother, child;
        cin >> d[0] >> v[0];
        ll g = gcd(d[0], v[0]);
        d[0] /= g, v[0] /= g;
        mother = v[0], child = d[0];
        for(int i = 1; i < n; i++){
            cin >> d[i] >> v[i];
            ll g = gcd(d[i], v[i]);
            d[i] /= g, v[i] /= g;
            mother = gcd(v[i], mother);
            child = lcm(d[i], child);
        }
        
        for(int i = 0; i < n; i++){
            cout << (child*v[i])/(d[i]*mother) << endl;
        }
    }
    return 0;
}