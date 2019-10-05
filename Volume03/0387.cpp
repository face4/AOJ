#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> v[n];
    for(int i = 0; i < n; i++){
        int m;  cin >> m;
        while(m-- > 0){
            int x;  cin >> x;
            v[i].push_back(x);
        }
    }
    priority_queue<int> q;
    ll ans = 0;
    for(int i = n-1; i >= 0; i--){
        for(int x : v[i])   q.push(x);
        ans += q.top(); q.pop();
    }
    cout << ans << endl;
    return 0;
}