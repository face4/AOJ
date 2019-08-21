#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m, x, y;
    cin >> n >> m;
    vector<int> a(n, -1);
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        for(int j = x-1; j <= y-1; j++)   a[j] = max(a[j], y-1);
    }
    int ans = 0, cur = 0;
    while(cur < n){
        if(a[cur] == -1){
            cout << "Impossible" << endl;
            return 0;
        }
        ans++;
        cur = a[cur]+1;
    }
    cout << ans << endl;
    return 0;
}