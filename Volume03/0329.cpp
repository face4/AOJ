#include<iostream>
#include<map>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll d[n+1];
    d[0] = 0;
    map<ll, int> pos;
    pos[0] = 0;
    int ans = 0;

    for(int i = 1; i <= n; i++){
        cin >> d[i];
        d[i] += d[i-1];
        if(pos.count(d[i]) == 1){
            ans = max(ans, i - pos[d[i]]);
        }else{
            pos[d[i]] = i;
        }
    }  

    cout << ans << endl;
    
    return 0;
}