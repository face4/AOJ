#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<bool> used(10000, 0);
vector<int> indeg(10000, 0), child[10000], res;

int main(){
    int v, e, s, t;
    cin >> v >> e;

    for(int i = 0; i < e; i++){
        cin >> s >> t;
        child[s].push_back(t);
        indeg[t]++;
    }

    queue<int> q;
    for(int i = 0; i < v; i++)  if(indeg[i] == 0)   q.push(i);

    while(!q.empty()){
        int x = q.front();  q.pop();
        used[x] = true;
        res.push_back(x);
        for(int c : child[x]){
            indeg[c]--;
            if(indeg[c] == 0)   q.push(c);
        }
    }

    for(int x : res)    cout << x << endl;

    return 0;
}