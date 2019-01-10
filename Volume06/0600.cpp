#include<iostream>
#include<numeric>
#include<vector>
using namespace std;

typedef long long ll;
int n;
vector<ll> a;
ll sum = 0;

bool f(ll x){
    for(int i = 1; i <= n; i++){
        auto first = lower_bound(a.begin(), a.end(), a[i-1]+x);
        if(first == a.end())    continue;
        ll s = *first-a[i-1];
        auto second = lower_bound(a.begin(), a.end(), *first+x);
        if(second == a.end())   continue;
        ll t = *second-*first;
        if(sum-s-t >= x)    return true;
    }
    return false;
}

int main(){
    cin >> n;

    a.resize(n+1);
    a[0] = 0;
    for(int i = 0; i < n; i++)  cin >> a[i+1];

    sum = accumulate(a.begin(), a.end(), 0ll);
    ll l = 1, r = sum;

    for(int i = 0; i < n; i++)  a[i+1] += a[i];

    while(r-l > 1){
        ll mid = (l+r)/2;
        if(f(mid))  l = mid;
        else        r = mid;
    }

    cout << l << endl;

    return 0;
}