// 解説を読んだ　面白い
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<numeric>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        vector<int> v[n];
        while(m-- > 0){
            int a, b;
            cin >> a >> b;
            a--, b--;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        bool ok = true;
        vector<int> col(n, -1);
        queue<int> q;
        q.push(0);
        col[0] = 0;
        for(int x : v[0])   col[x] = 1, q.push(x);
        while(!q.empty()){
            int x = q.front();  q.pop();
            for(int next : v[x]){
                ok &= col[next]==-1 || col[next]!=col[x];
                if(col[next] == -1)   col[next] = 1-col[x], q.push(next);
            }
        }
        if(!ok){
            cout << 0 << endl;
            continue;
        }
        int one = accumulate(col.begin(),col.end(), 0);
        set<int> res;
        if(one%2 == 0)  res.insert(one/2);
        if((n-one)%2 == 0)  res.insert((n-one)/2);
        cout << res.size() << endl;
        for(int x : res)    cout << x << endl;
    }
    return 0;
}