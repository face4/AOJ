#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int INF = 1<<30;

int main(){
    int n;
    cin >> n;

    if(n == 1){
        cout << 0 << endl;
        return 0;
    }

    vector<pair<int,int>> v[n];
    int s, t, w;

    for(int i = 0; i < n-1; i++){
        cin >> s >> t >> w;
        v[s].push_back({t,w});
        v[t].push_back({s,w});
    }

    vector<int> dist(n, INF);
    priority_queue<pair<int,int>> pq;
    pq.push({-0, 0});
    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        int cost = -p.first, pos = p.second;
        if(dist[pos] <= cost)   continue;
        dist[pos] = cost;
        for(pair<int,int> next : v[pos]){
            if(cost + next.second < dist[next.first]){
                pq.push({-(cost + next.second), next.first});
            }
        }
    }

    int a = -1, score = -1;
    for(int i = 0; i < n; i++){
        if(dist[i] > score){
            score = dist[i];
            a = i;
        }
    }
    dist.clear();
    dist.resize(n, INF);

    pq.push({-0, a});
    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        int cost = -p.first, pos = p.second;
        if(dist[pos] <= cost)   continue;
        dist[pos] = cost;
        for(pair<int,int> next : v[pos]){
            if(cost + next.second < dist[next.first]){
                pq.push({-(cost + next.second), next.first});
            }
        }
    }
    
    cout << *max_element(dist.begin(), dist.end()) << endl;

    return 0;
}