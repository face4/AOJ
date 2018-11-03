#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n, k;
    ll l, r;
    cin >> n >> k >> l >> r;

    ll a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    int left = n/2;
    int right = n - left;

    vector<ll> va[left+1], vb[right+1];

    for(int i = 0; i < 1<<left; i++){
        ll sum = 0;
        int popcnt = 0;
        for(int j = 0; j < left; j++){
            if(i>>j & 1)    sum += a[j], popcnt++;
        }
        va[popcnt].push_back(sum);
    }

    for(int i = 0; i < 1<<right; i++){
        ll sum = 0;
        int popcnt = 0;
        for(int j = 0; j < right; j++){
            if(i>>j & 1)    sum += a[left+j], popcnt++;
        }
        vb[popcnt].push_back(sum);
    }

    for(int i = 0; i <= left; i++)   sort(va[i].begin(), va[i].end());
    for(int i = 0; i <= right; i++)  sort(vb[i].begin(), vb[i].end());

    ll ans = 0;
    for(int i = 0; i <= left; i++){
        if(i + right < k)   continue;
        if(i > k)   break;

        for(int j = 0; j < va[i].size(); j++){
            ll tmp = va[i][j];
            ans += max(0ll, (ll)(upper_bound(vb[k-i].begin(), vb[k-i].end(), r-tmp) - 
                            lower_bound(vb[k-i].begin(), vb[k-i].end(), l-tmp)));
        }
    }

    cout << ans << endl;

    return 0;
}
