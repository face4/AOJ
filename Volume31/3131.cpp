#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    cin >> n >> k;
    if(n == 1){
        cout << k << endl;
        return 0;
    }
    ll low = 0, high = k+1;
    while(high-low > 1){
        ll mid = (high+low)/2;
        ll res = k-mid, bef = mid;
        bool f = false;
        for(ll i = 1; i < n; i++){
            ll tmp = bef/2;
            if(tmp == 0)    break;
            if(res < tmp){
                f = true;
                break;
            }
            res -= tmp;
            bef = tmp;
        }
        if(f)   high = mid;
        else    low = mid;
    }
    cout << low << endl;
    return 0;
}
