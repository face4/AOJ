#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int s;
    cin >> s;
    vector<int> v(s+1, 0);
    // O(S logS)
    for(int i = 1; i <= s; i++){
        if(s%i) continue;
        for(int j = 1; j*(j+1)/2 <= i; j++){
            if((i-j*(j+1)/2)%j == 0)    v[i]++;
        }
    }
    ll ans = 0;
    for(int i = 1; i <= s; i++){
        ans += v[i]*v[s/i];
    }
    cout << ans << endl;
    return 0;
}
