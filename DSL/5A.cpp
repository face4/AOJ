#include<iostream>
using namespace std;

int in[100001] = {}, out[100001] = {};

int main(){
    int n, t;
    cin >> n >> t;

    int l, r;
    for(int i = 0; i < n; i++){
        cin >> l >> r;
        in[l]++;
        out[r]++;
    }

    int inshop = 0;
    int ans = 0;
    for(int i = 0; i <= t; i++){
        inshop += in[i] - out[i];
        ans = max(ans, inshop);
    }

    cout << ans << endl;

    return 0;
}