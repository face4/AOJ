#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, m, u, v;
    while(cin >> n >> m, n+m){
        vector<int> path[n+1], deg(n+1);
        vector<bool> visit(n+1, 0);
        while(m-- > 0){
            cin >> u >> v;
            deg[u]++; deg[v]++;
            path[u].push_back(v);
            path[v].push_back(u);
        }

        bool valid = true;
        for(int i = 1; i <= n; i++){
            if(!visit[i]){
                queue<int> q;
                q.push(i);
                int one = 0, two = 0, more = 0;
                while(!q.empty()){
                    int x = q.front();  q.pop();
                    if(visit[x])    continue;
                    if(deg[x] == 1) one++;
                    if(deg[x] == 2) two++;
                    if(deg[x] > 2)  more++;
                    visit[x] = true;
                    for(int next : path[x]){
                        if(!visit[next])    q.push(next);
                    }
                }
                if(one+two+more == 0 || (one == 2 && more == 0))  continue;
                else valid = false;
            }
        }

        if(valid)   cout << "yes" << endl;
        else        cout << "no" << endl;
    }

    return 0;
}