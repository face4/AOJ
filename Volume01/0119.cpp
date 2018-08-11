// 多分トポロジカルソート
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;

    // 隣接リスト
    vector<int> adj[m+1];

    bool visit[m+1] = {};
    visit[2] = true;
    int indeg[m+1] = {};

    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        if(y != 2){
            adj[x].push_back(y);
            indeg[y]++;
        }
    }

    // topological sort
    while(1){
        int next = -1;
        for(int j = 1; j <= m; j++){
            if(!visit[j] && indeg[j] == 0){
                next = j;
                break;
            }
        }

        if(next == -1)  break;
        cout << next << endl;
        
        visit[next] = true;

        for(int x = 0; x < adj[next].size(); x++){
            indeg[adj[next][x]]--;
        }
    }

    cout << 2 << endl;

    return 0;
}