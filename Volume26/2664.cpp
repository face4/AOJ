#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, int> pri;
    for(int i = 0; i < n; i++){
        string s;   int x;
        cin >> s >> x;
        pri[s] = x;
    }
    int m;
    cin >> m;
    map<string, vector<string>> v;
    for(int i = 0; i < m; i++){
        string s, t;
        cin >> s >> t;
        v[s].push_back(t);
        v[t].push_back(s);
    }
    int ans = 0;
    map<string, int> visit;
    for(auto p : pri){
        if(visit.count(p.first))  continue;
        int val = p.second, cnt = 1;
        queue<string> q;
        q.push(p.first);
        visit[p.first] = 1;
        while(!q.empty()){
            string s = q.front();   q.pop();
            for(string t : v[s]){
                if(visit.count(t) == 0){
                    cnt++;
                    visit[t] = 1;
                    val = min(val, pri[t]);
                    q.push(t);
                }
            }
        }
        ans += cnt*val;
    }
    cout << ans << endl;
    return 0;
}