#include<iostream>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];

    map<int,ll> cnt;
    for(int i = 0; i < n; i++){
        int cp = a[i];
        for(int j = 2; j*j <= cp; j++){
            if(cp%j)    continue;
            cnt[j] += a[i];
            while(cp%j == 0)    cp /= j;
        }
        if(cp != 1) cnt[cp] += a[i];
    }

    ll ans = 0;
    for(auto p : cnt)   ans = max(ans, p.second);
    cout << ans << endl;

    return 0;
}
