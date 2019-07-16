#include<iostream>
#include<vector>
#include<queue>
#include<numeric>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0), indeg(n, 0), v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i]--;
        if(v[i] != -1)   indeg[v[i]]++;
    }
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0)   pq.push({k, i});
    }
    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        int x = p.first, y = p.second;
        if(a[y] == 1)    continue;
        a[y] = 1;
        if(x == 1 || v[y] == -1)    continue;
        if(a[v[y]] == 0) pq.push({x-1, v[y]});
    }
    for(int i = 0; i < n; i++)  if(v[i] == -1)   a[i] = 1;
    cout << accumulate(a.begin(), a.end(), 0) << endl;
    return 0;
}