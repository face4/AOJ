#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    ll old = stoll(s);
    int n = s.length();
    ll tens = 1;
    for(int i = 0; i < n; i++)  tens *= 10;
    ll ans = 0, diff = 0;
    // 3.6e6(worst)
    for(int s = 1; s < 1<<10; s++){
        string t = "";
        for(int j = 0; j < 10; j++){
            if((s>>j)&1)    t += ('0' + j);
        }
        if(t.length() != n) continue;
        do{
            ll tmp = stoll(t);
            ll tmpdiff = min(abs(tmp-old), tens-abs(tmp-old));
            if(tmpdiff > diff || (diff==tmpdiff && ans > tmp)){
                diff = tmpdiff;
                ans = tmp;
            }
        }while(next_permutation(t.begin(), t.end()));
    }
    cout << setw(n) << setfill('0') << ans << endl;
    return 0;
}