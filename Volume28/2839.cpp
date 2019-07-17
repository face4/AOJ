#include<iostream>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

int main(){
    ll n, m;
    cin >> n >> m;
    if(n == 1){
        cout << (m+1)%mod << endl;
    }else{
        ll d = (m+1)/(n-1)%mod;
        cout << ( (m+1)%(n-1)*(d+1)%mod*(d+1)%mod + (n-1-(m+1)%(n-1))*d%mod*d%mod )%mod << endl;
    }
    return 0;
}