#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a / gcd(a,b) * b;
}

int n;
ll p[101], q[101], r[101], b[101];

ll dfs(int pos){
    ll ret;
    if(r[pos] == 0){
        if(b[pos] == 0){
            ret = p[pos] + q[pos];
        }else{
            ll y = dfs(b[pos]);
            ll l = lcm(p[pos], q[pos]*y);
            ret = l/p[pos] + l/q[pos];
        }
    }else if(b[pos] == 0){
        ll x = dfs(r[pos]);
        ll l = lcm(p[pos]*x, q[pos]);
        ret = l/p[pos] + l/q[pos];
    }else{
        ll x = dfs(r[pos]), y = dfs(b[pos]);
        ll l = lcm(p[pos]*x, q[pos]*y);
        ret = l/p[pos] + l/q[pos];
    }
    return ret;
}

int main(){
    while(cin >> n, n){
        memset(p, 0, sizeof(p));
        memset(q, 0, sizeof(q));
        memset(r, 0, sizeof(r));
        memset(b, 0, sizeof(b));
        int indeg[101] = {};
        for(int i = 1; i <= n; i++){
            cin >> p[i] >> q[i] >> r[i] >> b[i];
            indeg[r[i]]++, indeg[b[i]]++;
            ll g = gcd(p[i], q[i]);
            p[i] /= g, q[i] /= g;
        }
        int root;
        for(root = 1; root <= n; root++)    if(indeg[root] == 0)    break;
        cout << dfs(root) << endl;
    }
}