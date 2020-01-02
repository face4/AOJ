#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll x;   cin >> x;
        ans += x-i-1;
    }
    cout << ans << endl;
    return 0;
}
