#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;
#define inRange(x,a,b) (a <= x && x <= b)

int main(){
    int n;
    string m;
    vector<int> p({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31});
    while(cin >> n >> m, n){
        vector<int> base(11, 0);
        vector<ll> cnt(11, 0);
        int cp = n;
        for(int i = 0; i < 11; i++){
            while(cp%p[i] == 0)  base[i]++, cp /= p[i];
        }
        ll val = 0;
        for(int i = 0; i < m.length(); i++){
            val *= n;
            if(inRange(m[i],'0','9'))   val += m[i]-'0';
            else                        val += 10+m[i]-'A';
        }
        for(int i = 0; i < 11; i++){
            ll x = val;
            while(x){
                cnt[i] += x/p[i];
                x /= p[i];
            }
        }

        ll ans = LLONG_MAX;
        for(int i = 0; i < 11; i++){
            if(base[i] == 0)    continue;
            ans = min(ans, cnt[i]/base[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
