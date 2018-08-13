#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, q, a, b, c;
    cin >> n >> q;

    vector<priority_queue<int>> pq(n);

    for(int i = 0; i < q; i++){
        cin >> a;

        if(a == 0){
            cin >> b >> c;
            pq[b].push(c);
        }else if(a == 1){
            cin >> b;
            if(!pq[b].empty())  cout << pq[b].top() << endl;
        }else if(a == 2){
            cin >> b;
            if(!pq[b].empty())  pq[b].pop();
        }
    }

    return 0;
}