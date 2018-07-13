#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];

    sort(a.begin(), a.end());

    double ans = -1;
    for(int i = 0; i < n-2; i++){
        ans = max(ans, (double)(a[n-1]+a[n-2]) / (a[i+1]-a[i]) );
    }

    ans = max(ans, (double)(a[n-1]+a[n-4]) / (a[n-2]-a[n-3]));
    ans = max(ans, (double)(a[n-3]+a[n-4]) / (a[n-1]-a[n-2]));

    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}