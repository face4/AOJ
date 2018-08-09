#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        if(n + m == 0)  break;

        n++;
        int p[n];
        p[0] = 0;
        for(int i = 1; i < n; i++)  cin >> p[i];

        vector<int> v;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                v.push_back(p[i]+p[j]);
            }
        }
        
        sort(v.begin(), v.end());

        int ans = 0;
        for(int i = 0; i < n*n; i++){
            int tmp = m - v[i];
            if(tmp < 0) continue;
            int tmp2 = *(upper_bound(v.begin(), v.end(), tmp) - 1);
            if(v[i] + tmp2 <= m) ans = max(ans, v[i] + tmp2);
        }

        cout << ans << endl;
    }
    return 0;
}