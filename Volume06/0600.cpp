#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n+1, 0);
    for(int i = 1; i <= n; i++)  cin >> a[i];
    for(int i = 1; i <= n; i++)  a[i] += a[i-1];
    
    ll l = 0, r = a[n];
    // 1e5*log(1e5)*2*log2(1e15) ~~ 1.6e8
    while(r-l > 1){
        ll mid = (l+r)/2;
        bool ok = false;
        for(int i = 0; i < n; i++){
            int j = lower_bound(a.begin(), a.end(), a[i]+mid)-a.begin();
            if(j >= n)    continue;
            int k = lower_bound(a.begin(), a.end(), a[j]+mid)-a.begin();
            if(k == n+1)    continue;
            ll last = a[n]-a[k]+a[i];
            if(last >= mid){
                ok = true;
                break;
            }
        }
        if(!ok)  r = mid;
        else     l = mid;
    }
    cout << l << endl;
    return 0;
}