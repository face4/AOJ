#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int n, l, a;
    cin >> n >> l;
    
    priority_queue<pair<int,int>> pq;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        cin >> a;
        pq.push({-a, i});
        if(i >= l-1){
            while(pq.top().second < i-(l-1))    pq.pop();
            ans.push_back(-pq.top().first);
        }
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " \n"[i == ans.size()-1];
    }
    
    return 0;
}