// 解説を見た
// 数列を昇順で見ていったとき、a[i]を置くことが出来るのはa[i]-t以上の要素の直前、もしくは末尾
// これは二分探索で計算できる
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    sort(v.begin(), v.end());
    ll ans = 1, mod = 1000000007;
    for(int i = 1; i < n; i++){
        int j = i-(lower_bound(v.begin(),v.end(),v[i]-t)-v.begin())+1; // (a[i]-t以上の要素数) + 末尾分の1
        ans *= j;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}