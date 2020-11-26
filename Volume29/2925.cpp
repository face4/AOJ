#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int h, w;
    cin >> h >> w;
    ll ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            ll x;  cin >> x;
            ans += x*(i+1)*(h-i)*(j+1)*(w-j);
        }
    }
    cout << ans << endl;
    return 0;
}