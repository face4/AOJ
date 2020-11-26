#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll a, b;
    int n;
    cin >> a >> b >> n;
    ll ans = 1ll<<60;
    for(int i = 1; i <= n; i++){
        if(b%i) continue;
        ll unit = b/i;
        for(int j = 1; j <= n; j++){
            ans = min(ans, abs(j*unit-a));
        }
    }
    cout << ans << endl;
    return 0;
}