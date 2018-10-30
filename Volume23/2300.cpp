#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    double l[n], a[n], b[n];
    for(int i = 0; i < n; i++)  cin >> l[i] >> a[i] >> b[i];

    double ans = 0;
    for(int i = 1; i < 1<<n; i++){
        vector<int> v;
        for(int j = 0; j < 21; j++){
            if((1<<j) & i)  v.push_back(j);
        }
        if(v.size() != m)   continue;

        double tmp = 0;
        for(int j = 0; j < m; j++){
            for(int k = j+1; k < m; k++){
                tmp += pow(l[v[j]]-l[v[k]], 2.0) + pow(a[v[j]]-a[v[k]], 2.0) + pow(b[v[j]]-b[v[k]], 2.0);
            }
        }

        ans = max(ans, tmp);
    }

    cout << fixed << setprecision(18) << ans << endl;

    return 0;
}