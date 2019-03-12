#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)
int di[5] = {0,0,1,-1,0};
int dj[5] = {1,-1,0,0,0};

int main(){
    map<char,int> act;
    act['5'] = 4;
    act['8'] = 3;
    act['6'] = 0;
    act['4'] = 1;
    act['2'] = 2;
    int h, w;
    while(cin >> h >> w, h+w){
        int si, sj, gi, gj;
        char mat[h][w];
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> mat[i][j];
                if(mat[i][j] == 'A')    si = i, sj = j;
                if(mat[i][j] == 'B')    gi = i, gj = j;
            }
        }
        vector<vector<int>> step(h, vector<int>(w, 1<<30));
        queue<pair<int, pair<int,int>>> q;
        q.push({0, {si, sj}});
        int maxstep;
        while(!q.empty()){
            auto p = q.front(); q.pop();
            int cost = p.first, i = p.second.first, j = p.second.second;
            if(step[i][j] <= cost)  continue;
            step[i][j] = cost;
            maxstep = cost;
            for(int k = 0; k < 4; k++){
                int ni = i+di[k], nj = j+dj[k];
                if(inRange(ni, 0, h) && inRange(nj, 0, w) && mat[ni][nj] != '#' && cost+1 < step[ni][nj]){
                    q.push({cost+1, {ni, nj}});
                }
            }
        }
        string s;
        cin >> s;
        int slen = s.length();
        int last = 0, turn = 0;
        vector<vector<bool>> ghost(h, vector<bool>(w, 0));
        bool meet = false;
        while(turn < maxstep+5 || turn-last < slen){
            int ngi = gi+di[act[s[turn%slen]]], ngj = gj+dj[act[s[turn%slen]]];
            if(!inRange(ngi, 0, h) || !inRange(ngj, 0, w))  ngi = gi, ngj = gj;
            gi = ngi, gj = ngj;
            if(!ghost[gi][gj]){
                last = turn+1;
                ghost[gi][gj] = true;
            }
            turn++;
            if(step[gi][gj] <= turn){
                cout << turn << " " << gi << " " << gj << endl;
                meet = true;
                break;
            }
        }

        if(!meet){
            cout << "impossible" << endl;
        }
    }
    return 0;
}