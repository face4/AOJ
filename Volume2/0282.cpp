#include<iostream>
#include<queue>
#include<climits>
using namespace std;

int main(){
    int n, r, l;
    cin >> n >> r >> l;

    int D[100001] = {};
    int T[100001] = {};

    int d, t, x;
    priority_queue<pair<int,int>> pq;
    for(int i = 1; i <= n; i++) pq.push({0, -i});
    int now = 0;

    for(int i = 0; i < r; i++){
        cin >> d >> t >> x;
        int diff = t-now;
        now = t;
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            if(D[-p.second] == p.first){
                T[-p.second] += diff;
                break;
            }
            pq.pop();
        }
        D[d] += x;
        pq.push({D[d], -d});
    }

    int ans, _max = INT_MIN;
    for(int i = 1; i <= n; i++){
        if(D[i] > _max){
            _max = D[i];
            ans = i;
        }
    }
    T[ans] += l-now;

    ans = 0, _max = INT_MIN;
    for(int i = 1; i <= n; i++){
        if(T[i] > _max){
            _max = T[i];
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}