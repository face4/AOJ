#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < n; i++){
        int s, t;   cin >> s >> t;
        pq.push({-t, s});
    }
    int now = 0, ans = 0;
    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        int f = p.second, e = -p.first;
        if(now < f){
            ans++;
            now = e;
        }
    }
    cout << ans << endl;
    return 0;
}