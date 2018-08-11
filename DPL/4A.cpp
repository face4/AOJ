#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n;
    ll v;
    cin >> n >> v;

    ll a[n], b[n], c[n], d[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++)  cin >> b[i];
    for(int i = 0; i < n; i++)  cin >> c[i];
    for(int i = 0; i < n; i++)  cin >> d[i];

    vector<ll> x, y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            x.push_back(a[i]+b[j]);
            y.push_back(c[i]+d[j]);
        }
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    ll cnt = 0;
    for(int i = 0; i < n*n; i++){
        ll res = v - x[i];
        if(res < y[0] || y[n*n-1] < res) continue;

        cnt += (upper_bound(y.begin(), y.end(), res) - lower_bound(y.begin(), y.end(), res));
    }

    cout << cnt << endl;

    return 0;
}