#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> c(n);
    for(int i = 0; i < n; i++)  cin >> c[i];
    sort(c.begin(), c.end());

    int x;
    while(q-- > 0){
        cin >> x;
        int ans = 0;
        for(int i = x; i <= (c[n-1]+x-1)/x*x; i+=x){
            auto it = lower_bound(c.begin(), c.end(), i);
            if(it != c.begin()) it--;
            ans = max(ans, (*it)%x);
            if(ans == x-1)  break;
        }
        cout << ans << endl;
    }

    return 0;
}