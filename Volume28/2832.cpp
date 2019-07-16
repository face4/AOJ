#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n, d;
    cin >> n >> d;
    int t, f, bt = 0, bf = 1;
    ll ans = 0, num = 0;
    while(n-- > 0){
        cin >> t >> f;
        if(t-bt < abs(f-bf)){
            ans = -1;
            break;
        }
        if(bf-1 + f-1 <= t-bt){
            ans += num * (bf-1);
            num = 0;
        }else if(num == d){
            ans = -1;
            break;
        }
        ans += num * abs(t-bt);
        num++;
        bt = t, bf = f;
    }
    if(ans != -1)   ans += num * (bf-1);
    cout << ans << endl;
    return 0;
}