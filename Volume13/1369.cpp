#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;

// 解説を読んだ　これを思いつけなかったのは反省
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++)  l[i] = r[i] = i;
    priority_queue<pair<int,int>> pq;
    while(m-- > 0){
        int x, y;
        cin >> x >> y;
        pq.push({-x, y});
    }
    while(!pq.empty()){
        auto p = pq.top();  pq.pop();
        int i = p.second;
        r[i-1] = max(r[i-1], r[i]);
        l[i] = min(l[i], l[i-1]);
    }
    for(int i = 0; i < n; i++)  cout << r[i]-l[i]+1 << " \n"[i+1==n];
    return 0;
}