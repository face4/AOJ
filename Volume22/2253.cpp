#include<iostream>
#include<queue>
using namespace std;

int dx[6] = {1,1,0,0,-1,-1};
int dy[6] = {0,1,1,-1,0,-1};

int main(){
    int t, n;
    while(cin >> t >> n, t+n){
        bool visit[121][121] = {};
        int x, y;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            visit[x+60][y+60] = true;
        }
        cin >> x >> y;
        queue<pair<pair<int,int>, int>> s;
        s.push({{x,y},0});
        int cnt = 0;
        while(!s.empty()){
            pair<pair<int,int>,int> p = s.front(); s.pop();
            if(p.second > t)    break;
            x = p.first.first, y = p.first.second;
            if(visit[x+60][y+60]) continue;
            cnt++;
            visit[x+60][y+60] = true;
            for(int k = 0; k < 6; k++){
                int nx = x + dx[k], ny = y + dy[k];
                if(!visit[nx+60][ny+60]){
                    s.push({{nx,ny},p.second+1});
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}