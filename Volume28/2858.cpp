#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> p;
    bool nonp[1000000] = {};
    nonp[0] = nonp[1] = true;
    for(int i = 2; i < 1000000; i++){
        if(nonp[i]) continue;
        p.push_back(i);
        for(int j = i+i; j < 1000000; j += i)   nonp[j] = true;
    }
    int l, r;
    cin >> l >> r;
    vector<int> v(r-l+1), cnt(r-l+1, 0);
    for(int i = 0; i <= r-l; i++){
        v[i] = l+i;
    }
    for(int x : p){
        int pos = (l+x-1)/x*x - l;
        while(pos <= r-l){
            while(v[pos]%x == 0)    v[pos] /= x, cnt[pos]++;
            pos += x;
        }
    }
    for(int i = 0; i <= r-l; i++)   if(v[i] != 1)   cnt[i]++;
    int ans = 0;
    for(int i = 0; i <= r-l; i++)   ans += !nonp[cnt[i]];
    cout << ans << endl;
    return 0;
}