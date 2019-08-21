#include<iostream>
#include<iomanip>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a / gcd(a,b) * b;
}

int main(){
    ll n, m;
    while(cin >> n >> m, n+m){
        ll cnt = 0, sum = 0, p[m];
        for(int i = 0; i < m; i++)  cin >> p[i];
        for(int i = 1; i < 1<<m; i++){
            vector<ll> v;
            for(int j = 0; j < m; j++){
                if((i>>j)&1)   v.push_back(p[j]);
            }
            ll val = v[0];
            for(ll j : v){
                val = lcm(val, j);
            }
            int num = v.size();
            if(num%2 == 0)      cnt -= n/val, sum -= n/val*(n/val+1)/2*val;
            else if(num%2 == 1) cnt += n/val, sum += n/val*(n/val+1)/2*val;
        }
        cnt = n-cnt;
        sum = n*(n+1)/2-sum;
        if(cnt == 0)    sum = 0, cnt = 1;
        cout << fixed << setprecision(12) << (double)sum/cnt << endl;
    }
    return 0;
}