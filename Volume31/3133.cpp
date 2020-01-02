#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

int main(){
    int x, y, z, n, m, s, t;
    cin >> x >> y >> z >> n >> m >> s >> t;
    s--, t--;
    s += x+y+z;
    t += x+y+z+n;
    int all = x+y+z+n+m;
    vector<int> v[all];
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        b += x;
        v[x+y+z+i].push_back(a);
        v[x+y+z+i].push_back(b);
        v[a].push_back(x+y+z+i);
        v[b].push_back(x+y+z+i);
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        a += x;
        b += x+y;
        v[x+y+z+n+i].push_back(a);
        v[x+y+z+n+i].push_back(b);
        v[a].push_back(x+y+z+n+i);
        v[b].push_back(x+y+z+n+i);
    }
    vector<int> d(all, 1<<30);
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while(!q.empty()){
        int x = q.front();  q.pop();
        if(x == t){
            cout << d[x]/2 << endl;
            return 0;
        }
        for(int next : v[x]){
            if(d[next] == 1<<30){
                d[next] = d[x]+1;
                q.push(next);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
