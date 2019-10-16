#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n;
    ll t;
    cin >> n >> t;
    ll sum = 0, ma = 0;
    for(int i = 0; i < n; i++){
        ll x;   cin >> x;
        ma = max(ma, x);
        sum += x;
        if(t < sum){
            cout << 1 << endl;
        }else{
            cout << (t-sum)/ma+1+1 << endl;
        }
    }
    return 0;
}