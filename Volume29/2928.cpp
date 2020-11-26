#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int h, w;
    cin >> h >> w;
    priority_queue<pii> pq;
    for(int i = 0; i < h; i++){
        int x;  cin >> x;
        pq.push({-x, 0});
    }
    for(int i = 0; i < w; i++){
        int x;  cin >> x;
        pq.push({-x, 1});
    }
    ll ans = 0;
    while(!pq.empty()){
        pii p = pq.top();   pq.pop();
        ll v = -p.first;
        int stat = p.second;
        if(stat == 0){
            ans += v*w;
            h--;
        }else if(stat == 1){
            ans += v*h;
            w--;
        }
    }
    cout << ans << endl;
    return 0;
}