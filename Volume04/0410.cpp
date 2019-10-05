#include<iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

int main(){
    int n;
    cin >> n;
    int x[n];
    for(int i = 0; i < n; i++)  cin >> x[i];
    int ans = 0;
    for(int i = 1; i < 1<<n; i++){
        ll tmp = 1;
        for(int j = 0; j < n; j++)  if((i>>j)&1)    tmp = lcm(tmp, x[j]);
        bool valid = true;
        for(int j = 0; j < n; j++)  if(((i>>j)&1) == 0) valid &= tmp%x[j]!=0;
        if(valid)   ans++;
    }
    cout << ans << endl;
    return 0;
}