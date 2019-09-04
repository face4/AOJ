#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int s, t, d;
    cin >> s >> t >> d;
    vector<ll> v(d);
    for(int i = 0; i < d; i++)  cin >> v[i], v[i] *= -1;
    ll target = s-t;
    ll sum = 0, ma = 0;
    for(int i = 0; i < d; i++){
        sum += v[i];
        if(sum >= target){
            cout << i+1 << endl;
            return 0;
        }
        ma = max(ma, sum);
    }
    if(sum <= 0){
        cout << -1 << endl;
        return 0;
    }
    ll ans = (target-ma+sum-1)/sum*d;
    target -= (target-ma+sum-1)/sum*sum;
    for(int i = 0; i <= d; i++){
        if(target <= 0){
            cout << ans+i << endl;
            return 0;
        }
        if(i < d)   target -= v[i];
    }
}

