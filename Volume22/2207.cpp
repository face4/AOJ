#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

const int INF = 1<<29;
int main(){
    int n;
    while(cin >> n, n){
        map<string, int> enc;
        vector<vector<int>> path(200, vector<int>(200, INF));
        int cnt = 0;
        string x, a, b, c;
        for(int i = 0; i < n; i++){
            cin >> x >> a >> x >> c >> b;
            int val = stoi(c.substr(3));
            if(enc.count(a) == 0)   enc[a] = cnt++;
            if(enc.count(b) == 0)   enc[b] = cnt++;
            path[enc[a]][enc[b]] = val;
            path[enc[b]][enc[a]] = -val;
        }
        // run dijkstra from all vertexes
        bool valid = true;
        for(int i = 0; i < cnt && valid; i++){
            vector<int> dp(cnt, INF);
            dp[i] = 0;
            queue<int> q;
            q.push(i);
            while(valid && !q.empty()){
                int pos = q.front(); q.pop();
                for(int j = 0; j < cnt; j++){
                    if(path[pos][j] == INF)   continue;
                    if(dp[j] == INF){
                        dp[j] = dp[pos]+path[pos][j];
                        q.push(j);
                    }else if(dp[pos]+path[pos][j] != dp[j]){
                        valid = false;
                        break;
                    }
                }
            }
        }
        cout << (valid ? "Yes" : "No") << endl;
    }
    return 0;
}