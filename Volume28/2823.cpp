#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        vector<int> vec[m];
        int d, v;
        for(int i = 0; i < n; i++){
            cin >> d >> v;
            vec[d-1].push_back(v);
        }
        int ans = 0;
        for(int i = 0; i < m; i++)  ans += *max_element(vec[i].begin(), vec[i].end());
        cout << ans << endl;
    }
    return 0;
}