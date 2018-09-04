#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int d;
    while(cin >> d, d){
        int n, m, k;
        cin >> n >> m;
        int a[n+1];
        a[0] = 0, a[n] = d;
        for(int i = 1; i < n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        
        int ans = 0;
        for(int i = 0; i < m; i++){
            cin >> k;
            int pos = lower_bound(a, a+n+1, k) - a - 1;
            ans += min(k-a[pos], a[pos+1]-k);
        }

        cout << ans << endl;
    }
    return 0;
}