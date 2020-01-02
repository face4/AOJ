#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 1-origin
struct BIT{
    int n, mod;
    vector<int> v;

    BIT(int _n, int _mod) : n(_n), mod(_mod){
        v.resize(n+1, 0);
    }

    void add(int k, int x){
        while(k <= n){
            (v[k] += x) %= mod;
            k += k&-k;
        }
    }

    int sum(int k){
        int ret = 0;
        while(k > 0){
            (ret += v[k]) %= mod;
            k -= k&-k;
        }
        return ret;
    }
};

typedef long long ll;

int main(){
    int a, b, p;
    while(cin >> a >> b >> p, p){
        int n = b-a+1;
        vector<string> vs;
        for(int i = 0; i < n; i++)  vs.push_back(to_string(a+i));
        sort(vs.begin(), vs.end());
        vector<int> rev(n);
        for(int i = 0; i < n; i++){
            rev[stoi(vs[i])-a] = i;
        }
        ll ans = 0;
        BIT bit(n, p);
        for(int i = 0; i < n; i++){
            ll tmp = bit.sum(rev[i])+1;
            (ans += tmp) %= p;
            bit.add(rev[i]+1, tmp);
        }
        cout << ans << endl;
    }

    return 0;
}