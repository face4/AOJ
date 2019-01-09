#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        vector<int> v(n+m);
        for(int i = 0; i < n+m; i++)    cin >> v[i];
        sort(v.begin(), v.end());
        int ans = v[0];
        for(int i = 1; i < n+m; i++)    ans = max(ans, v[i]-v[i-1]);
        cout << ans << endl;
    }
    return 0;
}