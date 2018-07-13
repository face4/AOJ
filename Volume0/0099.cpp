#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n, q, fish[1000001] = {};
    cin >> n >> q;
    priority_queue<pair<int,int>> pq;
    
    int a, v;
    for(int i = 0; i < q; i++){
        cin >> a >> v;
        fish[a] += v;
        pq.push({fish[a], -a});
        
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            if(p.first == fish[-p.second]){
                cout << -p.second << " " << p.first << endl;
                break;
            }
            pq.pop();
        }
        
    }
    
    return 0;
}
