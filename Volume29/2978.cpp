#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> pos(n, -1), rev(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(pos[a] != -1){
            cout << -1 << endl;
            return 0;
        }
        pos[a] = b;
        rev[b] = a;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(pos[i] == i) continue;
        ans++;
        int j = rev[i];
        swap(pos[i], pos[j]);
        rev[pos[j]] = j;
    }
    cout << ans << endl;
    return 0;
}
