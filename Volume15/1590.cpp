#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1<<30;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v[n];
    int a, b, c;
    while(m-- > 0){
        cin >> a >> b >> c;
        a--, b--;
        v[a].push_back({b,c});
    }
    priority_queue<pair<int,int>> pq;
    pq.push({-0, 0});
    vector<int> d(n, 1<<30);
    int ans = 0;
    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        int cost = -p.first, pos = p.second;
        if(d[pos] <= cost)  continue;
        d[pos] = cost;
        for(pair<int,int> q : v[pos]){
            int to = q.first, c = q.second;
            if(cost > c)    continue;
            if(to == n-1){
                ans = max(ans, c);
            }else if(d[to] > c){
                pq.push({-c, to});
            }
        }
    }
    cout << (ans == 0 ? -1 : ans) << endl;
    return 0;
}
