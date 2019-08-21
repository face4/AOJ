#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    vector<bool> inf(n, 0), vis(n, 0);
    vector<int> to(n);
    for(int i = 0; i < n; i++){
        if(vis[i])  continue;
        vis[i] = true;

        if(p[i] == 0){
            to[i] = i;
            continue;
        }

        int now = i + p[i];
        set<int> res;
        res.insert(i);
        while(!vis[now]){
            vis[now] = true;
            res.insert(now);
            now = now + p[now];
        }
        
        if(p[now] == 0){
            for(int v : res)    to[v] = now;
        }else if(res.count(now) || inf[now]){
            for(int v : res)    inf[v] = true;
        }else{
            for(int v : res)    to[v] = to[now];
        }
    }
    vector<int> step(n, 1<<30);
    step[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int i = q.front();  q.pop();
        if(i+6 >= n-1){
            cout << step[i]+(i!=n-1) << endl;
            break;
        }
        for(int j = 1; j <= 6; j++){
            if(inf[i+j])    continue;
            if(step[i]+1 < step[to[i+j]]){
                step[to[i+j]] = step[i]+1;
                q.push(to[i+j]);
            }
        }
    }
    return 0;
}