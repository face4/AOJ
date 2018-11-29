#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int cnt[100001] = {};
    int a[n], check = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] <= k && cnt[a[i]] == 0)  check++;
        cnt[a[i]]++;
    }

    if(check != k){
        cout << 0 << endl;
        return 0;
    }

    memset(cnt, 0, sizeof(cnt));
    int l = 0, r = 0, ans = n;
    check = 0;

    while(l < n){
        while(r < n && check < k){
            if(cnt[a[r]] == 0 && a[r] <= k) check++;
            cnt[a[r]]++;
            r++;
        }
        if(check < k)   break;
        ans = min(ans, r-l);
        if(cnt[a[l]] == 1 && a[l] <= k) check--;
        cnt[a[l]]--;
        l++;
    }

    cout << ans << endl;

    return 0;
}