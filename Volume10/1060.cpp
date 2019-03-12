#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    while(cin >> n, n){
        vector<int> num;
        for(ll i = 2; i*i <= n; i++){
            int t = 0;
            while(n%i == 0) n /= i, t++;
            if(t)   num.push_back(t);
        }
        if(n != 1)  num.push_back(1);
        ll ans = 1;
        for(int t : num){
            ans *= 2*t+1;
        }
        cout << (ans+1)/2 << endl;
    }
    return 0;
}