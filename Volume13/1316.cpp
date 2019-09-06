#include<iostream>
#include<map>
#include<cstring>
using namespace std;

bool used[10][20];

int main(){
    int h, w;
    while(cin >> h >> w, h+w){
        char mat[h][w];
        for(int i = 0; i < h; i++)  for(int j = 0; j < w; j++)  cin >> mat[i][j];
        map<string,int> cnt;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                for(int di = -1; di <= 1; di++){
                    for(int dj = -1; dj <= 1; dj++){
                        if(di == 0 && dj == 0)  continue;
                        memset(used, 0, sizeof(used));
                        string acc = "";
                        int si = i, sj = j;
                        while(!used[si][sj]){
                            acc += mat[si][sj];
                            cnt[acc]++;
                            used[si][sj] = true;
                            si += di, sj += dj;
                            si = (si + h) % h;
                            sj = (sj + w) % w;
                        }
                    }
                }
            }
        }
        string ans = "0";
        for(pair<string,int> p : cnt){
            if(p.second > 1 && p.first.length() > ans.length()) ans = p.first;
        }
        cout << ans << endl;
    }
    return 0;
}