#include<iostream>
#include<queue>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    priority_queue<pii> pq;
    for(int i = 0; i <= k; i++)   pq.push({a[i], -i});
    int ret[n-k], rind = 0, next = k+1, now = 0;
    while(true){
        pii p = pq.top();   pq.pop();
        if(now > -p.second) continue;
        ret[rind++] = p.first;
        now = -p.second;
        if(rind == n-k) break;
        pq.push({a[next], -next});
        next++;
    }
    for(int i = 0; i < n-k; i++)    cout << ret[i];
    cout << endl;
    return 0;
}