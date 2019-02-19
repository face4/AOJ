#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> l(c);
    for(int i = 0; i < c; i++)  cin >> l[i];
    priority_queue<pair<int,int>> pq;
    int a, b;
    while(n-- > 0){
        cin >> a >> b;
        pq.push({b, a-1});
    }
    int cnt = 0, sum = 0;
    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        if(cnt == m)    break;
        if(l[p.second] == 0)    continue;
        sum += p.first, cnt++, l[p.second]--;
    }
    cout << sum << endl;
    return 0;
}