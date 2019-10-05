#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n, T;
    cin >> n >> T;
    ll t = 1000000000/T;
    
    string s;
    cin >> s;
    ll sum = 0;
    int pos = 0;
    bool overflow = false;
    while(pos < s.length()){
        pos+=2;
        ll now = 1;
        int beki = s[pos++]-'0';
        while(beki-- > 0){
            now *= n;
            if(now+sum > t){
                overflow = true;
                break;
            }
        }
        sum += now;
        pos++;  // +
    }
    if(!overflow && sum <= t)   cout << sum*T << endl;
    else                        cout << "TLE" << endl;
    return 0;
}