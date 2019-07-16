#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), v;
    vector<bool> visit(n, 0);
    for(int i = 0; i < n; i++)  cin >> a[i];
    int ans = 0;
    for(int pos = 0; pos < n; pos++){
        int i = pos;
        if(visit[i])    continue;
        while(!visit[i]){
            v.push_back(i);
            visit[i] = true;
            i = (i + a[i])%n;
        }
        int vlen = v.size();
        for(int j = 0; j < vlen; j++){
            if(v[j] == i){
                ans += vlen-j;
                break;
            }
        }
        v.clear();
    }
    cout << ans << endl;
    return 0;
}