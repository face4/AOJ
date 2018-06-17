#include<iostream>
#include<stack>
using namespace std;

char mat[500][500];
int dp[500][500];
int h, w;

int solve(){
    int ret = -1;

    for(int i = 0; i < h; i++){
        // 長方形の左端、高さを積む
        stack<pair<int,int>> s;
        for(int j = 0; j < w; j++){
            if(s.empty()){
                s.push({j, dp[i][j]});
            }else if(s.top().second < dp[i][j]){
                s.push({j, dp[i][j]});
            }else if(s.top().second > dp[i][j]){
                int lastl;
                while(!s.empty() && s.top().second > dp[i][j]){
                    pair<int,int> out = s.top(); s.pop();
                    ret = max(ret, (j-out.first)*(out.second));
                    lastl = out.first;
                }
                s.push({lastl, dp[i][j]});
            }else if(s.top().second == dp[i][j]){
                // do nothing.
            }
        }

        while(!s.empty()){
            pair<int,int> out = s.top(); s.pop();
            ret = max(ret, (w-out.first)*out.second);
        }
    }

    return ret;
}

int main(){
    while(cin >> h >> w){
        if(w + h == 0)  break;

        // input
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> mat[i][j];
            }
        }

        // preparation
        for(int j = 0; j < w; j++){
            if(mat[0][j]=='.')  dp[0][j] = 1;
            else                dp[0][j] = 0;
        }
        for(int i = 1; i < h; i++){
            for(int j = 0; j < w; j++){
                if(mat[i][j]=='.')  dp[i][j] = dp[i-1][j]+1;
                else                dp[i][j] = 0;
            }
        }

        // solve
        cout << solve() << endl;
    }

    return 0;
}