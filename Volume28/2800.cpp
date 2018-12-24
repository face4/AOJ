// なんかうまく書けない
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int cnt[3] = {}, a;
    for(int i = 0; i < n; i++){
        cin >> a;
        cnt[a%3]++;
    }

    if(cnt[1] > cnt[2]) swap(cnt[1], cnt[2]);

    if(cnt[2] == 0){
        cout << 1 << endl;
        return 0;
    }

    int ans = 1 + cnt[0];
    cnt[2]--;
    for(int i = 0;;i++){
        if(cnt[2-i%2] == 0) break;
        ans++;
        cnt[2-i%2]--;
    }

    cout << min(n, ans+1) << endl;

    return 0;
}