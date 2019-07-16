#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll a, b;
    cin >> a >> b;
    if(b%a == 0){
        cout << -1 << endl;
        return 0;
    }
    for(ll add = 0; add <= a; add++){
        ll c = b + add;
        ll greed = c/b + c%b/a + c%b%a, susp = c/a + c%a;
        if(susp < greed){
            cout << b+add << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
