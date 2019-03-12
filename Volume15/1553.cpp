#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> d(n), c(n);
    for(int i = 0; i < n; i++)  cin >> d[i] >> c[i];
    vector<int> dp(200001, 1<<30);
    priority_queue<pair<int, int>> pq;
    pq.push({-0, 0});
    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        int cost = -p.first, pos = p.second;
        if(cost >= dp[pos]) continue;
        dp[pos] = cost;
        if(pos == x)    break;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                int next = pos + (2*j-1)*d[i];
                if(inRange(next, 0, 200001) && dp[next] > cost+c[i]){
                    pq.push({-(cost+c[i]), next});
                }
            }
        }
    }
    cout << (dp[x] == 1<<30 ? -1 : dp[x]) << endl;
    return 0;
}