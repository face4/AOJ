#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n-- > 0){
        int h, w;
        cin >> h >> w;
        int si[26], ei[26], sj[26], ej[26];
        for(int i = 0; i < 26; i++) si[i] = h, sj[i] = w, ei[i] = ej[i] = -1;
        char mat[h][w];
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> mat[i][j];
                if(mat[i][j] == '.')    continue;
                int ind = mat[i][j]-'A';
                si[ind] = min(si[ind], i);
                sj[ind] = min(sj[ind], j);
                ei[ind] = max(ei[ind], i);
                ej[ind] = max(ej[ind], j);
            }
        }
        bool safe = true;
        int dp[26][26] = {};
        for(int x = 0; x < 26; x++){
            if(ei[x] == -1) continue;
            for(int i = si[x]; i <= ei[x]; i++){
                for(int j = sj[x]; j <= ej[x]; j++){
                    if(mat[i][j] == '.'){
                        safe = false;
                        continue;
                    }
                    if(mat[i][j]-'A' == x)  continue;
                    dp[x][mat[i][j]-'A'] = -1;
                }
            }
        }
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(dp[i][k] == 0 || dp[k][j] == 0)  continue;
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }
        }
        for(int i = 0; i < 26; i++) safe &= (dp[i][i] == 0);
        cout << (safe ? "SAFE" : "SUSPICIOUS") << endl;
    }
    return 0;
}