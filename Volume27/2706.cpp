#include<iostream>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int p, q;
    cin >> p >> q;
    
    int g = gcd(p, q);
    p /= g, q /= g;

    int ans = 1;
    for(int i = 2; i*i <= q; i++){
        if(q % i == 0){
            ans *= i;
            while(q % i == 0)   q /= i;
        }
    }
    ans *= q;

    cout << ans << endl;
    return 0;
}