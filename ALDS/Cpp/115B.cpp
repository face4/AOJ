#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

typedef pair<int,int> p;
typedef long long ll;

int main(){
    int n, w;
    cin >> n >> w;
    vector<p> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i].first >> v[i].second;
    sort(v.rbegin(), v.rend(), [](p a, p b){return (ll)a.first*b.second < (ll)b.first*a.second;});
    double ans = 0;
    for(int i = 0; i < n; i++){
        int take = min(w, v[i].second);
        ans += (double)take / v[i].second * v[i].first;
        w -= take;
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}