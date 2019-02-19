#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v;
    // sentinel
    v.push_back(0);
    v.push_back(1000000001);

    int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        v.push_back(a[i]);
        v.push_back(b[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int len = v.size();

    auto l = [&](int val)->int{
        return lower_bound(v.begin(),v.end(),val)-v.begin();
    };
    auto r = [&](int val)->int{
        return upper_bound(v.begin(),v.end(),val)-v.begin();
    };

    vector<int> cnt(len, 0);
    for(int i = 0; i < n; i++){
        cnt[l(a[i])]++;
        cnt[r(b[i])]--;
    }

    int ans = 0;
    for(int i = 1; i < len; i++){
        cnt[i] += cnt[i-1];
        ans = max(ans, cnt[i]);
    }

    cout << ans << endl;

    return 0;
}