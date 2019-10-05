#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dijkstra(int from, vector<int>* v, vector<int> &d){
    queue<int> q;
    q.push(from);
    d[from] = 0;
    while(!q.empty()){
        int x = q.front();  q.pop();
        for(int next : v[x]){
            if(d[next] != 1<<30)    continue;
            d[next] = d[x]+1;
            q.push(next);
        }
    }
}

typedef long long ll;

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    
    vector<int> v[n];
    while(m-- > 0){
        int x, y;
        cin >> x >> y;
        x--, y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    vector<int> a(n, 1<<30), b(n, 1<<30);
    dijkstra(s, v, a);
    dijkstra(t, v, b);

    vector<int> cnta(n+1, 0), cntb(n+1, 0);
    for(int i = 0; i < n; i++)  if(a[i] != 1<<30)   cnta[a[i]]++;
    for(int i = 0; i < n; i++)  if(b[i] != 1<<30)   cntb[b[i]]++;

    ll ans = 0;
    for(int i = 0; i <= a[t]-2; i++){
        ans += (ll)(cnta[i]) * cntb[a[t]-2-i];
    }
    cout << ans << endl;

    return 0;
}