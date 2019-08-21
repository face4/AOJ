#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

struct BIT{
    int siz;
    vector<int> node;
    BIT(int n){
        siz = n;
        node.resize(siz+1, 0);
    }

    int query(int i){
        int ret = 0;
        while(i > 0){
            ret += node[i];
            i -= i&-i;
        }
        return ret;
    }

    void add(int i, int x){
        while(i <= siz){
            node[i] += x;
            i += i&-i;
        }
    }
};

int main(){
    int n, r;
    while(cin >> n, n){
        vector<int> a(n);
        for(int i = 0; i < n; i++)  a[i] = i;
        cin >> r;
        while(r-- > 0){
            int s, t;
            cin >> s >> t;
            swap(a[--s], a[--t]);
        }
        vector<ll> v(n, 1);
        for(int i = 1; i < n; i++)  v[i] = (v[i-1]*i)%mod;
        BIT bit(n);
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans += (a[i]-bit.query(a[i]))*v[n-1-i]%mod;
            ans %= mod;
            bit.add(a[i]+1, 1);
        }
        cout << ans << endl;
    }
    return 0;
}