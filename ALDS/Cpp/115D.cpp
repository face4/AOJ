#include<iostream>
#include<queue>
using namespace std;

int main(){
    string t;
    cin >> t;
    int cnt[26] = {};
    for(char c : t) cnt[c-'a']++;
    priority_queue<int> pq;
    for(int i = 0; i < 26; i++){
        if(cnt[i])  pq.push(-cnt[i]);
    }
    if(pq.size() == 1){
        cout << t.length() << endl;
        return 0;
    }
    int ans = 0;
    while(pq.size() > 1){
        int p = pq.top();   pq.pop();
        int q = pq.top();   pq.pop();
        ans -= p+q;
        pq.push(p+q);
    }
    cout << ans << endl;
    return 0;
}