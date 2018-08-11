#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    set<ll> s;

    ll a[3];
    for(int i = 0; i < n; i++){
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a+3);
        s.insert(a[2] + 10000*a[1] + 100000000*a[0]);
    }

    cout << n-(int)(s.size()) << endl;
    return 0;
}