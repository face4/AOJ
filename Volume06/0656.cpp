#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n+1];
    for(int i = 1; i <= n; i++)  cin >> a[i];
    vector<int> lfrom[n+1], r(n+1);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        lfrom[x].push_back(y);
    }
    priority_queue<int> pq;
    for(int i = 1; i <= n; i++){
        for(int j : lfrom[i])   pq.push(j);
        while(!pq.empty() && pq.top() < i)    pq.pop();
        r[i] = pq.empty() ? i : pq.top();
    }
    vector<ll> dp(n+1, 0);
    ll val = 0;
    for(int i = 1; i <= n; i++){
        dp[r[i]] = max(dp[r[i]], val+a[i]);
        val = max(val, dp[i]);
    }
    cout << val << endl;
    return 0;
}