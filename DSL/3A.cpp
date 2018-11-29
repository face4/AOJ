#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main(){
    int n, 
    s;
    cin >> n >> s;

    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];

    if(accumulate(a.begin(), a.end(), 0) < s){
        cout << 0 << endl;
        return 0;
    }

    int l = 0, r = 0, sum = 0, ans = n;
    while(l < n){
        while(r < n && sum < s){
            sum += a[r];
            r++;
        }
        if(sum < s)  break;
        ans = min(ans, r-l);
        sum -= a[l];
        l++;
    }

    cout << ans << endl;

    return 0;
}