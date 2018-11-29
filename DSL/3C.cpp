#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n, q;
    cin >> n >> q;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    ll x;
    while(q-- > 0){
        cin >> x;
        ll ans = 0;
        int l = 0, r = 0;
        ll sum = 0;
        while(l < n){
            while(r < n && sum+a[r] <= x){
                sum += a[r];
                r++;
            }
            ans += r-l;
            sum -= a[l];
            l++;
        }
        cout << ans << endl;
    }

    return 0;
}