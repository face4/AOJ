#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int main(){
    int n, r, k, t;
    cin >> n;

    map<int, vector<int>> path;
    for(int i = 0; i < n; i++){
        cin >> r >> k;
        for(int j = 0; j < k; j++){
            cin >> t;
            path[r].push_back(t);
        }
    }

    int p, s, d, v;
    cin >> p;
    for(int i = 0; i < p; i++){
        cin >> s >> d >> v;
        queue<pair<int, int>> q;
        set<int> appear;

        q.push({s,1});

        int ans = -1;
        while(!q.empty()){
            pair<int,int> p = q.front();    q.pop();
            if(appear.find(p.first) != appear.end())   continue;
            
            if(p.first == d){
                ans = p.second;
                break;
            }

            appear.insert(p.first);

            for(int j = 0; j < path[p.first].size(); j++){
                if(appear.find(path[p.first][j]) == appear.end()){
                    q.push({path[p.first][j], p.second+1});
                }
            }
        }

        if(ans == -1 || ans > v){
            cout << "NA" << endl;
        }else{
            cout << ans << endl;
        }
    }

    return 0;
}