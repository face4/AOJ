#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

int main(){
    char a, b;
    int h, w, s, t;
    cin >> h >> w >> a >> b;
    s = a - 'A', t = b - 'A';

    char mat[h][w];
    for(int i = 0; i < h*w; i++)    cin >> mat[i/w][i%w];

    vector<int> v[26];
    for(int i = 1; i < h-1; i++){
        for(int j = 1; j < w-1; j++){
            if(!inRange(mat[i][j], 'A', 'Z'))   continue;
            int from = mat[i][j]-'A';
            if(i+2 < h && mat[i+2][j] == '|'){
                int ni = i+2;
                while(mat[ni][j]=='|')  ni++;
                ni++;
                int to = mat[ni][j]-'A';
                v[from].push_back(to);
                v[to].push_back(from);
            }
            if(j+2 < w && mat[i][j+2] == '-'){
                int nj = j+2;
                while(mat[i][nj]=='-')  nj++;
                nj++;
                int to = mat[i][nj]-'A';
                v[from].push_back(to);
                v[to].push_back(from);
            }
        }
    }
    const int INF = 1<<29;
    vector<int> dp(26, INF);
    queue<int> q;
    q.push(s);
    dp[s] = 0;
    while(!q.empty()){
        int x = q.front();  q.pop();
        for(int next : v[x]){
            if(dp[next] == INF){
                dp[next] = dp[x]+1;
                q.push(next);
            }
        }
    }
    cout << dp[t] << endl;
    return 0;
}