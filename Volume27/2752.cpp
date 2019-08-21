#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    if(n == 0){
        cout << 0 << endl;
    }else{
        int ans = 0;
        ll acc = 1;
        while(acc <= n){
            ans++;
            acc *= 2;
        }
        cout << ans << endl;
    }
    return 0;
}
