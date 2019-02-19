#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t-- > 0){
        int n, k, x, y;
        cin >> n >> k >> x;
        vector<int> v(n-1);
        for(int i = 0; i < n-1; i++){
            cin >> y;
            v[i] = y-x;
            x = y;
        }
        sort(v.rbegin(), v.rend());
        int ans = 0;
        for(int i = k-1; i < n-1; i++)  ans += v[i];
        cout << ans << endl;
    }

    return 0;
}