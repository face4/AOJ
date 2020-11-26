#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int cnt[1<<20] = {};

// bucket method
int main(){
    int n, k, x0;
    cin >> n >> k >> x0;
    if(x0 == 0){
        cout << 0 << endl;
        return 0;
    }
    unsigned long long int x = x0;
    for (int i = 0; i < n; i++) {
        ll tmp = (long long int)x;
        cnt[(1<<19)+(tmp>>44)]++;
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
    }
    int key = 0;
    for(key = 0; key < 1<<20; key++){
        if(k-cnt[key] <= 0) break;
        k -= cnt[key];
    }
    x = x0;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        ll tmp = (long long int)x;
        if((1<<19)+(tmp>>44) == key)    v.push_back(tmp);
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
    }
    sort(v.begin(), v.end());
    cout << v[k-1] << endl;
    return 0;
}