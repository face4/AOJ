#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

const int mod = 1000000007;

int main(){
    ll m;
    cin >> m;
    string s;
    cin >> s;
    vector<ll> v(10, 0);
    for(int i = 0; i < 10; i++){
        ll tmp = 0;
        for(int j = 0; j < s.length(); j++){
            tmp *= 10;
            tmp %= mod;
            if(s[j]-'0' != i)   continue;
            tmp++;
        }
        v[i] = tmp;
    }
    vector<int> x({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    do{
        if(s.length() > 1 && x[s[0]-'0'] == 0)    continue;
        ll tmp = 0;
        for(int i = 0; i < 10; i++){
            tmp += v[i] * x[i];
            tmp %= mod;
        }
        if(tmp == m){
            for(char c : s) cout << x[c-'0'];
            cout << endl;
            return 0;
        }
    }while(next_permutation(x.begin(), x.end()));
    cout << -1 << endl;
    return 0;
}
