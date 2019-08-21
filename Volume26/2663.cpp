#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    a.push_back(0);
    sort(a.begin(), a.end());
    vector<ll> sum = a;
    for(int i = 1; i <= n; i++)  sum[i] += sum[i-1];
    int m;
    cin >> m;
    vector<ll> b(m);
    for(int i = 0; i < m; i++){
        int x;  cin >> x;
        b[i] = sum[upper_bound(a.begin(), a.end(), x)-a.begin()-1];
    }
    for(int i = 0; i < m; i++){
        ll x;   cin >> x;
        cout << (b[i] >= x ? "Yes" : "No") << endl;
    }
    return 0;
}