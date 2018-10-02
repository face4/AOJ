#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        vector<int> a(n);
        for(int i = 0; i < n; i++)  cin >> a[i];
        sort(a.begin(), a.end());
        if(a[0]+a[1] > m){
            cout << "NONE" << endl;
            continue;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i] >= m)    break;
            int j = lower_bound(a.begin(), a.end(), m-a[i])-a.begin();
            if(j >= n || a[j]+a[i] > m)   j--;
            if(j >= 0 && i != j)  ans = max(ans, a[i]+a[j]);
        }
        cout << ans << endl;
    }
    return 0;
}