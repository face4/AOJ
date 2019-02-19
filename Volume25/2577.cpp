#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
    int h, w, d, n;
    cin >> h >> w >> d >> n;

    int si, sj;
    char mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'D')    si = i, sj = j;
        }
    }

    vector<int> r(d);
    for(int i = 0; i < d; i++)  cin >> r[i];

    vector<int> x(n), y(n), s(n);
    for(int i = 0; i < n; i++)  cin >> x[i] >> y[i] >> s[i];

    vector<vector<int>> cnt(h, vector<int>(w, 0));
    vector<vector<bool>> prob(h, vector<bool>(w, true));

    // 絶対に財宝が存在しえないマスを先に列挙しておく
    for(int i = 0; i < n; i++){
        if(s[i] == 0)   continue;
        bool valid = false;
        for(int j = 0; j < h; j++){
            for(int k = 0; k < w; k++){
                if(max(abs(j-y[i]), abs(k-x[i])) <= r[s[i]-1]){
                    prob[j][k] = false;
                }
            }
        }
    }



    bool isBroken = false;
    // 財宝の存在を確かめる
    for(int i = 0; i < n; i++){
        bool valid = false;
        if(s[i] == d){
            for(int j = 0; j < h; j++){
                for(int k = 0; k < w; k++){
                    int dis = max(abs(j-y[i]), abs(k-x[i]));
                    if(dis > r[s[i]-1]){
                        cnt[j][k]++;
                        if(prob[j][k])  valid = true;
                    }
                }
            }
        }else{
            for(int j = 0; j < h; j++){
                for(int k = 0; k < w; k++){
                    int dis = max(abs(j-y[i]), abs(k-x[i]));
                    if((s[i] == 0 || dis > r[s[i]-1]) && dis <= r[s[i]]){
                        cnt[j][k]++;
                        if(prob[j][k])  valid = true;
                    }
                }
            }
        }
        if(!valid)  isBroken = true;
    }

    vector<pair<int,int>> treasure;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(cnt[i][j] == n && prob[i][j] && mat[i][j] != '#')    treasure.push_back({i,j});
        }
    }

    if(treasure.size() == 0)    isBroken = true;

    if(isBroken){
        cout << "Broken" << endl;
        return 0;
    }

    queue<pair<int,int>> q;
    vector<vector<bool>> visit(h, vector<bool>(w, 0));
    q.push({si, sj});
    while(!q.empty()){
        auto p = q.front(); q.pop();
        int i = p.first, j = p.second;
        if(visit[i][j]) continue;
        visit[i][j] = true;
        for(int k = 0; k < 4; k++){
            int ni = i + di[k], nj = j + dj[k];
            if(inRange(ni, 0, h) && inRange(nj, 0, w) && !visit[ni][nj] && mat[ni][nj] == '.'){
                q.push({ni, nj});
            }
        }
    }

    int reach = 0;
    for(int i = 0; i < treasure.size(); i++){
        reach += (visit[treasure[i].first][treasure[i].second]);
    }

    string answer = "";
    if(reach == 0)                      answer = "No";
    else if(reach == treasure.size())   answer = "Yes";
    else                                answer = "Unknown";

    cout << answer << endl;

    return 0;
}