#include<iostream>
using namespace std;

int main(){
    int n, m, t, a;
    cin >> n >> m >> t;

    bool occupied[10001] = {};
    for(int i = 0; i < n; i++){
        cin >> a;
        for(int j = max(0, a-m); j < min(t, a+m); j++) occupied[j] = true;
    }

    int ans = 0;
    for(int i = 0; i < t; i++) if(!occupied[i])  ans++;
    
    cout << ans << endl;

    return 0;
}